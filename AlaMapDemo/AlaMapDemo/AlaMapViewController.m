//
//  AlaMapViewController.m
//  AlaMapDemo
//
//  Created by Qian JX on 16/8/16.
//  Copyright © 2016年 zfsoft. All rights reserved.
//

#import "AlaMapViewController.h"

@interface AlaMapViewController ()
@property (nonatomic, retain) MKCircle *circle;
@end

@implementation AlaMapViewController
@synthesize myMapView;
@synthesize circle;

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.myMapView = [[ALDMapView alloc] initWithFrame:self.view.frame BGType:BGTYPE_GRID MapTool:MAPTOOL_DISPLAY_NORMAL];
    self.myMapView.delegate = self;
    self.view.backgroundColor = [UIColor whiteColor];
    [self.view addSubview:self.myMapView];
    
    //添加折线
    if (circle == nil) {
        CLLocationCoordinate2D coor;
        coor.latitude = 30.27888972;
        coor.longitude = 120.16520048;
        circle = [MKCircle circleWithCenterCoordinate:coor radius:500];
    }
//    [self.myMapView addOverlay:circle];

    CLLocationCoordinate2D commuterLotCoords[5]={
        CLLocationCoordinate2DMake(30.27888972, 120.16520048),
        CLLocationCoordinate2DMake(30.27888982, 120.16520048),
        CLLocationCoordinate2DMake(30.27888982, 120.16520058),
        CLLocationCoordinate2DMake(30.27888972, 120.16520058),
        CLLocationCoordinate2DMake(30.27888972, 120.16520048)
    };
//    MKPolygon *polygon = [MKPolygon polygonWithCoordinates:coor1, coor2, coor3, coor4 count:4];
    MKPolygon *polygon = [MKPolygon polygonWithCoordinates:commuterLotCoords count:5];
    [self.myMapView addOverlay:polygon];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)viewWillAppear:(BOOL)animated{
    [super viewWillAppear:animated];
    [myMapView initMap];
}

- (void)viewDidAppear:(BOOL)animated{
    [super viewDidAppear:animated];
    [self addPinAnnotation];
}
/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
 */
// 添加大头针
- (void)addPinAnnotation
{
//    if (pointAnnotation == nil) {
       ALDPointAnnotation *pointAnnotation = [[ALDPointAnnotation alloc] initWithType:ANNOTATION_TYPE_PIN];
        pointAnnotation.coordinate = CLLocationCoordinate2DMake(30.27790744, 120.16203466);
        pointAnnotation.index = 1;
        pointAnnotation.title = @"标注1";
        pointAnnotation.subtitle = @"30.27790744, 120.16203466";
//    }
    [myMapView addAnnotation:pointAnnotation];
}


#pragma mark - ALD MapView Delegate
- (MKAnnotationView *)mapView:(ALDMapView *)mapView viewForAnnotation:(id <MKAnnotation>)annotation{
    if (((ALDPointAnnotation *)annotation).type == ANNOTATION_TYPE_PIN) {
        //大头针
        ALDPinAnnotationView *annotationView = [[ALDPinAnnotationView alloc] initWithAnnotation:annotation reuseIdentifier:nil];
        // 设置颜色
        annotationView.pinColor = MKPinAnnotationColorRed;
        // 从天上掉下效果
        annotationView.animatesDrop = YES;
        annotationView.canShowCallout = YES;
        return annotationView;
    } else {
        return nil;
    }
}

- (MKOverlayView *)mapView:(ALDMapView *)mapView viewForOverlay:(id<MKOverlay>)overlay{
    if ([overlay isKindOfClass:[MKCircle class]])
    {
        ALDCircleView* circleView = [[ALDCircleView alloc] initWithOverlay:overlay];
        circleView.fillColor = [[UIColor redColor] colorWithAlphaComponent:0.5];
        circleView.strokeColor = [[UIColor blueColor] colorWithAlphaComponent:0.5];
        circleView.lineWidth = 5.0;
        return circleView;
    }
    if ([overlay isKindOfClass:[MKPolygon class]]){
        ALDPolygonView *polygonView = [[ALDPolygonView alloc] initWithOverlay:overlay];
        polygonView.lineDash = NO;
        return polygonView;
    }
    return nil;
}
@end
