//
//  AlaMapViewController.m
//  AlaMapDemo
//
//  Created by Qian JX on 16/8/16.
//  Copyright © 2016年 zfsoft. All rights reserved.
//

#import "AlaMapViewController.h"

@interface AlaMapViewController ()
@property (nonatomic, retain) ALDMapView *mapView;
@end

@implementation AlaMapViewController
@synthesize mapView;

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.mapView = [[ALDMapView alloc] initWithFrame:self.view.frame BGType:BGTYPE_GRID MapTool:MAPTOOL_DISPLAY_NORMAL];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)viewWillAppear:(BOOL)animated{
    [super viewWillAppear:animated];
    [mapView initMap];
}
/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
