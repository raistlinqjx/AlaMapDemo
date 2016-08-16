//
//  ALDRouteObject.h
//  ALDMapKit
//
//  Created by tvMac on 15/5/24.
//  Copyright (c) 2015年 edushi. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "ALDSearchCommonHeader.h"

///导航线路坐标信息
@interface ALDRoutePoint : NSObject

///经度
@property (nonatomic, assign)double longitude;
///纬度
@property (nonatomic, assign)double latitude;
///屏幕坐标，内部转换用。初始化时可以不设置
@property (nonatomic, assign)CGPoint point;

/**
 *初始化路径点对象
 *@param coord 经纬度坐标值
 *@return ALDRoutePoint对象
 */
- (id)initWithLocation:(CLLocationCoordinate2D)coord;

@end

///导航路径对象
@interface ALDRouteObject : NSObject

///导航线路经纬度数组。成员类型为ALDRoutePoint
@property (nonatomic, readonly, retain)NSArray *points;

///导航类型
@property (nonatomic, readonly, assign)NAVI_TYPE_ENUM type;

/**
 *初始化导航路径对象
 *@param points 导航线路坐标信息数组
 *@param type 导航类型
 */
- (id)initWithPoints:(NSArray *)points type:(NSInteger)type;

@end
