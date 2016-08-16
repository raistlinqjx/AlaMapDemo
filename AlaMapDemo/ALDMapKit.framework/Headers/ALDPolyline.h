//
//  ALDPolyline.h
//  ALDMapKit
//
//  Created by apple on 15/12/15.
//  Copyright © 2015年 edushi. All rights reserved.
//

#import <MapKit/MapKit.h>

/// 自定义折线
@interface ALDPolyline : MKMultiPoint <MKOverlay>

/// 折线经纬度数组。成员类型为ALDRoutePoint
@property (nonatomic, readonly, retain)NSArray *routes;

/**
 *根据指定坐标点生成一段折线
 *@param coords 指定的经纬度坐标点数组
 *@param count 坐标点的个数
 *@return 新生成的折线对象
 */
+ (ALDPolyline *)polylineWithCoordinates:(CLLocationCoordinate2D *)coords count:(NSUInteger)count;

/**
 *根据导航线路坐标信息点生成一段折线
 *@param routes 导航线路坐标信息点数组
 *@return 新生成的折线对象
 */
+ (ALDPolyline *)polylineWithRouteArray:(NSArray *)routes;

@end
