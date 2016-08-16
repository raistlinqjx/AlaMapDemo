//
//  ALDSimpleGeoManager.h
//  ALDMapKit
//
//  Created by apple on 15/12/9.
//  Copyright © 2015年 edushi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

///离线地理编码服务
@interface ALDSimpleGeoManager : NSObject

///行政区编码（例：杭州 330100）
@property (nonatomic, assign)NSInteger ac;
///省份
@property (nonatomic, retain)NSString *province;
///城市
@property (nonatomic, retain)NSString *city;
///当前经纬度
@property (nonatomic, assign)CLLocationCoordinate2D pt;

/**
 *初始化（单实例）
 *@return 单实例
 */
+ (ALDSimpleGeoManager *)sharedManager;

/**
 *初始化当前城市信息
 *@param coordinate 经纬度
 */
- (void)initWithCurrentLocation:(CLLocationCoordinate2D)coordinate;

/**
 *离线经纬度转省份，矩形碰撞可能返回多个省份
 *@param coordinate 经纬度
 *@return 所属省份
 */
- (NSArray *)reverseProvinceWithCoordinate:(CLLocationCoordinate2D)coordinate;

/**
 *离线经纬度转城市，多边形碰撞只返回单个城市
 *@param coordinate 经纬度
 *@return 所属城市
 */
- (NSDictionary *)reverseCityWithCoordinate:(CLLocationCoordinate2D)coordinate;

@end
