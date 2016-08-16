//
//  ALDGeocoder.h
//  ALDMapKit
//
//  Created by Wengys on 15/1/26.
//  Copyright (c) 2015年 edushi. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "ALDSearchCommonHeader.h"

/// 弧度转角度
#define RadiansToDegrees(radians)   (radians * 180.0/M_PI)
/// 角度转弧度
#define DegreesToRadians(degrees)   (degrees * M_PI / 180.0)
/// 度分秒(DMS)转度(DDD)
#define DMS2Degree(d,m,s)  (d + m/60.0 + s/3600.0)

///三维地图上世界坐标对象
@interface ALDMapWorldPoint : NSObject

///地图x坐标
@property (nonatomic, assign)NSUInteger mapX;
///地图y坐标
@property (nonatomic, assign)NSUInteger mapY;

@end

///仿真三维地图上相应的像素坐标
@interface ALDGeocoder : NSObject

///被转换点所在瓦片的列号
@property (nonatomic, assign)NSInteger TileCol;
///被转换点所在瓦片的行号
@property (nonatomic, assign)NSInteger TileRow;
///被转换点相对其所在瓦片左上角点的横向偏移，单位是像素
@property (nonatomic, assign)NSInteger xoffset;
///被转换点相对其所在瓦片左上角点的纵向偏移，单位是像素
@property (nonatomic, assign)NSInteger yoffset;

/**
 *设定屏幕瓦片大小,地图以外直接使用时必须优先设置
 *@param width 瓦片宽,单位像素
 *@param height 瓦片高,单位像素
 */
+ (void)initGeocoderWidth:(NSInteger)width Height:(NSInteger)height;

/**
 *获取瓦片宽对应地面的实际宽
 *@param level 瓦片的级数
 */
+ (double)getTileActualWidthByMapLevel:(NSInteger)level;

/**
 *获取两个地理位置(经纬度)间的实际距离，单位是米
 *@param coorFrom 起点经纬度
 *@param coorTo 终点经纬度
 */
+ (double)getDistance:(CLLocationCoordinate2D)coorFrom to:(CLLocationCoordinate2D)coorTo;

/**
 *经纬度坐标转换到仿真三维地图上相应的地图坐标
 *@param coordinate 被转换点的经纬度
 *@param level 瓦片的级数
 *@return ALDMapWorldPoint 地图坐标
 */
+ (ALDMapWorldPoint *)coordinate2WorldPoint:(CLLocationCoordinate2D)coordinate MapLevel:(NSInteger)level;

/**
 *仿真三维地图上相应的地图坐标转换到经纬度坐标
 *@param worldPoint 被转换点的地图坐标
 *@param level 瓦片的级数
 *@return CLLocationCoordinate2D 经纬度
 */
+ (CLLocationCoordinate2D)worldPoint2Coordinate:(ALDMapWorldPoint *)worldPoint MapLevel:(NSInteger)level;

/**
 *经纬度坐标转换到仿真三维地图上相应的像素坐标，仿真三维地图的坐标是经纬度坐标通过mercator投影，并经过两次旋转后得到
 *@param coordinate 被转换点的经纬度
 *@param level 瓦片的级数
 *@return ALDGeocoder 像素坐标
 */
+ (ALDGeocoder *)Mercator2R:(CLLocationCoordinate2D)coordinate MapLevel:(NSInteger)level;

/**
 *仿真三维地图上相应的像素坐标转换到经纬度坐标，仿真三维地图的坐标是经纬度坐标通过mercator投影，并经过两次旋转后得到
 *@param level 瓦片的级数
 *@param row 瓦片的行号
 *@param col 瓦片的列号
 *@param offsetX 相对其所在瓦片左上角点的横向偏移，单位是像素
 *@param offsetY 相对其所在瓦片左上角点的纵向偏移，单位是像素
 *@return CLLocationCoordinate2D 被转换点的经纬度
 */
+ (CLLocationCoordinate2D)RevMercator2R:(NSInteger)level TileRow:(NSInteger)row TileCol:(NSInteger)col OffsetX:(NSInteger)offsetX OffsetY:(NSInteger)offsetY;

/**
 *地球坐标系 (WGS-84) 到仿真三维地图坐标系 的转换
 *@param 地球坐标系 (WGS-84)
 *@return CLLocationCoordinate2D 仿真三维地图坐标系
 */
+ (CLLocationCoordinate2D)WorldGS2WebMercator:(CLLocationCoordinate2D)coordinate;

/**
 *仿真三维地图坐标系 到地球坐标系 (WGS-84) 的转换
 *@param 仿真三维地图坐标系
 *@return CLLocationCoordinate2D 地球坐标系 (WGS-84)
 */
+ (CLLocationCoordinate2D)WebMercator2WorldGS:(CLLocationCoordinate2D)coordinate;

/**
 *地球坐标系 (WGS-84) 到火星坐标系 (GCJ-02) 的转换
 *@param 地球坐标系 (WGS-84)
 *@return CLLocationCoordinate2D 火星坐标系 (GCJ-02)
 */
+ (CLLocationCoordinate2D)WorldGS2MarsGS:(CLLocationCoordinate2D)coordinate;

/**
 *火星坐标系 (GCJ-02) 到地球坐标系 (WGS-84) 的转换
 *@param 火星坐标系 (GCJ-02)
 *@return CLLocationCoordinate2D 地球坐标系 (WGS-84)
 */
+ (CLLocationCoordinate2D)MarsGS2WorldGS:(CLLocationCoordinate2D)coordinate;

/**
 *火星坐标系 (GCJ-02) 到百度坐标系 (BD-09) 的转换
 *@param 火星坐标系 (GCJ-02)
 *@return CLLocationCoordinate2D 百度坐标系 (BD-09)
 */
+ (CLLocationCoordinate2D)MarsGS2BaiduGS:(CLLocationCoordinate2D)coordinate;

/**
 *百度坐标系 (BD-09) 到火星坐标系 (GCJ-02) 的转换
 *@param 百度坐标系 (BD-09) 
 *@return CLLocationCoordinate2D 火星坐标系 (GCJ-02)
 */
+ (CLLocationCoordinate2D)BaiduGS2MarsGS:(CLLocationCoordinate2D)coordinate;

/**
 *地球坐标系 (WGS-84) 到百度坐标系 (BD-09) 的转换
 *@param 地球坐标系 (WGS-84)
 *@return CLLocationCoordinate2D 百度坐标系 (BD-09)
 */
+ (CLLocationCoordinate2D)WorldGS2BaiduGS:(CLLocationCoordinate2D)coordinate;

/**
 *百度坐标系 (BD-09) 到地球坐标系 (WGS-84) 的转换
 *@param 百度坐标系 (BD-09)
 *@return CLLocationCoordinate2D 地球坐标系 (WGS-84)
 */
+ (CLLocationCoordinate2D)BaiduGS2WorldGS:(CLLocationCoordinate2D)coordinate;

/**
 *地球坐标系 (WGS-84) 到搜狗坐标系 (Sogou) 的转换
 *@param 地球坐标系 (WGS-84)
 *@return CLLocationCoordinate2D 搜狗坐标系 (Sogou)
 */
+ (CLLocationCoordinate2D)WorldGS2SogouGS:(CLLocationCoordinate2D)coordinate;

/**
 *搜狗坐标系 (Sogou) 到地球坐标系 (WGS-84) 的转换
 *@param 搜狗坐标系 (Sogou)
 *@return CLLocationCoordinate2D 地球坐标系 (WGS-84)
 */
+ (CLLocationCoordinate2D)SogouGS2WorldGS:(CLLocationCoordinate2D)coordinate;

/**
 *地球坐标系 (WGS-84) 到墨卡托坐标系 (Mercator) 的转换
 *@param 地球坐标系 (WGS-84)
 *@return CLLocationCoordinate2D 墨卡托坐标系 (Mercator)
 */
+ (CLLocationCoordinate2D)WorldGS2Mercator:(CLLocationCoordinate2D)coordinate;

/**
 *墨卡托坐标系 (Mercator) 到地球坐标系 (WGS-84) 的转换
 *@param 墨卡托坐标系 (Mercator) 
 *@return CLLocationCoordinate2D 地球坐标系 (WGS-84)
 */
+ (CLLocationCoordinate2D)Mercator2WorldGS:(CLLocationCoordinate2D)mercator;

/**
 *根据中心点经纬度计算Gid
 *@param coordinate 中心点经纬度
 *@return Gid
 */
+ (NSString *)getGidWithGPS:(CLLocationCoordinate2D)coordinate;

/**
 *根据中心点经纬度计算Gid 及 四角经纬度
 *@param coordinate 中心点经纬度
 *@return Gid 及 四角经纬度
 */
+ (NSDictionary *)MathGidWithGPS:(CLLocationCoordinate2D)coordinate;

@end
