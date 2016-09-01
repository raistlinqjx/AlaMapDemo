//
//  SearchTableVC.m
//  GaoDeDemo
//
//  Created by GAO on 16/8/3.
//  Copyright © 2016年 GAO. All rights reserved.
//

#import "SearchTableVC.h"//AMapTip
@interface SearchTableVC ()

@end

@implementation SearchTableVC
- (instancetype)initWithStyle:(UITableViewStyle)style
{
    self = [super initWithStyle:style];
    if(!self)
    {
        return nil;
    }
    self.view.frame = CGRectMake(0, 64, [UIScreen mainScreen].bounds.size.width, 200);
    self.myMapView = [ALDMapView new];
    return self;
}
- (void)viewDidLoad
{
    [super viewDidLoad];
    [self.tableView setBackgroundColor:[UIColor colorWithWhite:1 alpha:0.9]];
    self.searchResult = [NSMutableArray array];
    // Uncomment the following line to preserve selection between presentations.
    // self.clearsSelectionOnViewWillAppear = NO;
    
    // Uncomment the following line to display an Edit button in the navigation bar for this view controller.
    // self.navigationItem.rightBarButtonItem = self.editButtonItem;
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    
}

#pragma mark - Table view data source

//- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
//{
//
//}
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    
    if([self.searchResult count])
    {
        return [self.searchResult count];
    }
    return 0;
}


- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    //UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:<#@"reuseIdentifier"#> forIndexPath:indexPath];
    //AMapTip
    static NSString *str = @"asfasf";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:str];
    if(cell == nil)
    {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:str];
    }
//    AMapPOI *pio = [self.searchResult objectAtIndex:indexPath.row];
//    AMapTip *tip = [self.searchResult objectAtIndex:indexPath.row];
//    cell.textLabel.text = pio.name;
//    cell.detailTextLabel.text = pio.address;
//    NSLog(@"%@",tip.uid);
//    NSLog(@"%@",tip.adcode);
//    NSLog(@"%@",tip.location);
    
    
    return cell;
    
    
}
- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    [tableView setHidden:YES];
    
//    [_mapView removeAnnotationsAndOverlays];
//    
//    AMapPOI *pio = [self.searchResult objectAtIndex:indexPath.row];
//    CLLocationCoordinate2D coordinate;
//    coordinate.latitude = pio.location.latitude;
//    coordinate.longitude = pio.location.longitude;
//    
//    MAPointAnnotation *pointAnnotation = [[MAPointAnnotation alloc] init];
//    pointAnnotation.coordinate = coordinate;
//    pointAnnotation.title = pio.name;
//    pointAnnotation.subtitle = pio.address;
//    [_mapView setCenterCoordinate:coordinate animated:YES];
//    [_mapView addAnnotation:pointAnnotation];
    
}

/*
// Override to support conditional editing of the table view.
- (BOOL)tableView:(UITableView *)tableView canEditRowAtIndexPath:(NSIndexPath *)indexPath {
    // Return NO if you do not want the specified item to be editable.
    return YES;
}
*/

/*
// Override to support editing the table view.
- (void)tableView:(UITableView *)tableView commitEditingStyle:(UITableViewCellEditingStyle)editingStyle forRowAtIndexPath:(NSIndexPath *)indexPath {
    if (editingStyle == UITableViewCellEditingStyleDelete) {
        // Delete the row from the data source
        [tableView deleteRowsAtIndexPaths:@[indexPath] withRowAnimation:UITableViewRowAnimationFade];
    } else if (editingStyle == UITableViewCellEditingStyleInsert) {
        // Create a new instance of the appropriate class, insert it into the array, and add a new row to the table view
    }   
}
*/

/*
// Override to support rearranging the table view.
- (void)tableView:(UITableView *)tableView moveRowAtIndexPath:(NSIndexPath *)fromIndexPath toIndexPath:(NSIndexPath *)toIndexPath {
}
*/

/*
// Override to support conditional rearranging of the table view.
- (BOOL)tableView:(UITableView *)tableView canMoveRowAtIndexPath:(NSIndexPath *)indexPath {
    // Return NO if you do not want the item to be re-orderable.
    return YES;
}
*/

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
