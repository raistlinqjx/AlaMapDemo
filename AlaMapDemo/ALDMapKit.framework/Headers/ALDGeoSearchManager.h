//
//  ALDGeoSearchManager.h
//  ALDMapKit
//
//  Created by Wengys on 15/3/19.
//  Copyright (c) 2015年 edushi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@protocol ALDGeoSearchDelegate;

///geo搜索服务
@interface ALDGeoSearchManager : NSObject

/// 检索模块的Delegate
@property (nonatomic, assign) id<ALDGeoSearchDelegate> delegate;

/**
 *地理编码
 *@param address    地址
 *@param block      回调
 */
+ (void)geocoderWithAddress:(NSString *)address
                   andBlock:(void (^)(NSArray* placeList))block;

/**
 *逆地理编码(地址)
 *@param latitude   经度
 *@param longitude  纬度
 *@param block      回调
 */
+ (void)reverseGeocoderWithLatitude:(double)latitude
                          longitude:(double)longitude
                           andBlock:(void (^)(NSString* placeAddress))block;

/**
 *逆地理编码(字典)
 *@param coordinate 经纬度
 *@param block      回调
 */
+ (void)reverseGeocoderWithCoordinate:(CLLocationCoordinate2D)coordinate
                             andBlock:(void (^)(NSDictionary *placemark))block;

/**
 *根据地址名称获取地理信息
 *异步函数，返回结果在ALDGeoSearchDelegate的-mapView:onGetGeocoder:result:errorCode:通知
 *@param geoAddress 地址名称
 *@return 成功返回YES，否则返回NO
 */
- (BOOL)geoCode:(NSString *)geoAddress;

/**
 *根据地理坐标获取地址信息
 *异步函数，返回结果在ALDGeoSearchDelegate的-mapView:onGetReverseGeocoder:result:errorCode:通知
 *@param coordinate 地理坐标(经纬度)
 *@return 成功返回YES，否则返回NO
 */
- (BOOL)reverseGeoCode:(CLLocationCoordinate2D)coordinate;

@end

///搜索delegate，用于获取搜索结果
@protocol ALDGeoSearchDelegate <NSObject>
@optional
/**
 *返回地址信息搜索结果
 *@param searcher 搜索对象
 *@param result 搜索结果
 *@param error 错误号
 */
- (void)onGetGeoCodeResult:(NSString *)searcher result:(NSArray *)result errorCode:(NSError *)error;

/**
 *返回反地理编码搜索结果
 *@param searcher 搜索对象
 *@param result 搜索结果
 *@param error 错误号
 */
- (void)onGetReverseGeoCodeResult:(CLLocationCoordinate2D)searcher result:(NSString *)result errorCode:(NSError *)error;

@end
