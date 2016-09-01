//
//  AlaMapNaviViewController.m
//  AlaMapDemo
//
//  Created by Qian JX on 16/8/22.
//  Copyright © 2016年 zfsoft. All rights reserved.
//

#import "AlaMapNaviViewController.h"
#import "SearchTableVC.h"
@interface AlaMapNaviViewController (){
    SearchTableVC *_tableVC;
}
@property (nonatomic, retain) NSMutableArray *annotationArray;
@property (nonatomic, assign) BOOL              isClickSearch;
@end

@implementation AlaMapNaviViewController
@synthesize search, mapView;
@synthesize annotationArray;
@synthesize isClickSearch;

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    [self initMap];
    [self initSearch];
    [self initSearchTable];
    [self searchService];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)initSearch
{
    self.search = [[UISearchController alloc]initWithSearchResultsController:_tableVC];
    search.searchBar.frame = CGRectMake(self.search.searchBar.frame.origin.x, self.search.searchBar.frame.origin.y, self.search.searchBar.frame.size.width, 44.0);
    search.dimsBackgroundDuringPresentation = NO;          //是否添加半透明覆盖层
    search.hidesNavigationBarDuringPresentation = NO;       //是否隐藏导航栏
    search.obscuresBackgroundDuringPresentation = NO;       //搜索时，背景变模糊
    //    search.hidesBottomBarWhenPushed = NO;
    search.searchResultsUpdater = self;
    search.searchBar.delegate = self;
    [search.searchBar setTintColor:[UIColor redColor]];  //搜索时光标颜色
    [search.searchBar setPlaceholder:@"输入地点或地址"];
    for (UIGestureRecognizer *tap in search.searchBar.gestureRecognizers)
    {
        [search.searchBar removeGestureRecognizer:tap];
    }
    
    for (UIView *view in  [[[search.searchBar subviews] objectAtIndex:0] subviews])
    {
        if ([view isKindOfClass:[NSClassFromString(@"UINavigationButton") class]])
        {
            UIButton * cancel =(UIButton *)view;
            [cancel setTitle:@"取消" forState:UIControlStateNormal];
        }
    }
    
    if (search.searchBar)
    {
        self.navigationItem.titleView = search.searchBar;
        //        [self.navigationController.navigationBar addSubview:search.searchBar];
    }
    annotationArray = [NSMutableArray array];
}

-(void)initSearchTable
{
    _tableVC = [[SearchTableVC alloc] initWithStyle:UITableViewStylePlain];
    _tableVC.myMapView = mapView;
}

- (void)initMap
{
//    _mapView = [[MAMapView alloc] initWithFrame:CGRectMake(0, 0, self.view.bounds.size.width, self.view.bounds.size.height)];
//    _mapView.showsIndoorMap = YES;
//    _mapView.delegate = self;
//    _mapView.showsUserLocation = YES;                                           //使用定位服务
//    //   [_mapView setUserTrackingMode:MAUserTrackingModeFollowWithHeading];       //定位模式
//    
//    //    _mapView.pausesLocationUpdatesAutomatically = NO;                     //设置即使应用被挂起，也持续定位
//    //    _mapView.allowsBackgroundLocationUpdates = YES;                       //允许持续定位
//    
//    //将指定学校设置为地图中心点120.08666039 30.30446546
//    [_mapView setCenterCoordinate:CLLocationCoordinate2DMake(30.30446546, 120.08666039)];
//    self.definesPresentationContext = YES;
//    [self.view addSubview:_mapView];
    
    self.mapView = [[ALDMapView alloc] initWithFrame:self.view.frame BGType:BGTYPE_GRID MapTool:MAPTOOL_DISPLAY_NORMAL];
    [self.mapView initMapWithCoordinate:CLLocationCoordinate2DMake(30.30446546, 120.08666039)];
    self.mapView.delegate = self;
    self.view.backgroundColor = [UIColor whiteColor];
    [self.view addSubview:self.mapView];
}

- (void)searchService
{
//    searchAPI = [[AMapSearchAPI alloc]init];
    
//    searchAPI.delegate = self;
}

-(void)exitKeyboard
{
    if ([search.searchBar isFirstResponder])
    {
        [search.searchBar resignFirstResponder];
    }
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

#pragma mark - UISearchResultsUpdating

- (void)updateSearchResultsForSearchController:(UISearchController *)searchController
{
    NSString *searchString = [searchController.searchBar text];
    
    //    [AMapSearchObject searchKeywords:searchString andCity:@"杭州" andSearchApi:_searchAPI]; //关键字搜索
    
//    [ALDPoiSearchManager poiSearchCity:330100 input:searchString countPerPage:20 page:1 andBlock:^(NSString *input, NSArray *placeList) {
//        if (placeList) {
//            annotationArray = [NSMutableArray arrayWithArray:placeList];
////            [resultView reloadData];
//        } else {
//            UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"检索失败" message:@"请检查输入的内容后再重试" delegate:nil cancelButtonTitle:@"关闭" otherButtonTitles:nil];
//            [alert show];
//        }
//    }];
//    CLLocationCoordinate2D corr = CLLocationCoordinate2DMake(30.30446546, 120.08666039);
    
//    [ALDGeocoder convertADCodeWithCoordinate:corr completion:^(AD_CODE_ENUM ad) {
//        searchCode = ad;
//    }];

    
    
    [ALDPoiSearchManager poiSearchCity:330100 input:searchString countPerPage:20 page:1 andBlock:^(NSArray *placeList){
        if (placeList) {
            annotationArray = [NSMutableArray arrayWithArray:placeList];
//            [resultView reloadData];
            NSLog(@"%@", annotationArray.description);
        } else {
//            UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"检索失败" message:@"请检查输入的内容后再重试" delegate:nil cancelButtonTitle:@"关闭" otherButtonTitles:nil];
//            [alert show];
            NSLog(@"无搜索结果");
        }
    }];
    if(!searchString.length)
    {
        return;
    }
    _tableVC.tableView.hidden = YES;
}
#pragma mark UISearchBarDelegate
//点击搜索
- (void)searchBarSearchButtonClicked:(UISearchBar *)searchBar
{
    NSString *keywords = searchBar.text;
//    [AMapSearchObject searchPolygon:keywords andPiontsArray:[self returnZheDaPoint] andSearchApi:searchAPI];
    [ALDPoiSearchManager poiSearchCity:330100 input:keywords countPerPage:20 page:1 andBlock:^(NSArray *placeList){
        if (placeList) {
            annotationArray = [NSMutableArray arrayWithArray:placeList];
            //            [resultView reloadData];
        } else {
            UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"检索失败" message:@"请检查输入的内容后再重试" delegate:nil cancelButtonTitle:@"关闭" otherButtonTitles:nil];
            [alert show];
        }
    }];

    isClickSearch = YES;
}

- (void)searchBarCancelButtonClicked:(UISearchBar *)searchBar
{
//    [_mapView removeAnnotationsAndOverlays];
}

- (void)searchBarResultsListButtonClicked:(UISearchBar *)searchBar{
    
}
- (void)searchBar:(UISearchBar *)searchBar selectedScopeButtonIndexDidChange:(NSInteger)selectedScope
{
    
}


@end
