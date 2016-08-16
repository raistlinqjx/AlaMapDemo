//
//  ALDPoiSearchManager.h
//  ALDMapKit
//
//  Created by Wengys on 15/3/7.
//  Copyright (c) 2015年 edushi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ALDPoiSearchResultObject.h"

///矩形检索参数信息
typedef struct {
    CLLocationCoordinate2D leftBottom;     ///< 左下角点经纬度坐标
    CLLocationCoordinate2D rightTop;       ///< 右上角点经纬度坐标
} ALDPoiSearchBounds;

@protocol ALDPoiSearchDelegate;

///POI检索服务
@interface ALDPoiSearchManager : NSObject

/**
 *周边关键字搜索接口
 *@param input  关键字或首字母或拼音
 *@param coords 中心点经纬度
 *@param range  查询范围，半径，单位为米
 *@param num    每页的条数
 *@param page   请求的为第几页
 *@param block  回调接口
 */
+ (void)poiSearchNearByWithKey:(NSString *)input
                        coords:(CLLocationCoordinate2D)coords
                         range:(NSInteger)range
                  countPerPage:(NSInteger)num
                          page:(NSInteger)page
                      andBlock:(void (^)(NSArray* placeList))block;

/**
 *关键字查询接口
 *@param ac     行政区编号
 *@param input  关键字或首字母或拼音
 *@param num    每页的条数
 *@param page   请求的为第几页
 *@param block  回调接口
 */
+ (void)poiSearchCity:(NSInteger)ac
                input:(NSString *)input
         countPerPage:(NSInteger)num
                 page:(NSInteger)page
             andBlock:(void (^)(NSArray* placeList))block;

/**
 *周边查询接口
 *@param type   POI分类
 *@param coords 中心点经纬度
 *@param range  查询范围，半径，单位为米
 *@param num    每页的条数
 *@param page   请求的为第几页
 *@param block  回调接口
 */
+ (void)poiSearchNearBy:(NSInteger)type
                 coords:(CLLocationCoordinate2D)coords
                  range:(NSInteger)range
           countPerPage:(NSInteger)num
                   page:(NSInteger)page
               andBlock:(void (^)(NSArray* placeList))block;

/**
 *拉框查询接口
 *@param bounds 矩形区域,结构类型(ALDPoiSearchBounds)
 *@param type   POI分类
 *@param num    每页的条数
 *@param page   请求的为第几页
 *@param block  回调接口
 */
+ (void)poiSearchInbounds:(ALDPoiSearchBounds)bounds
                 poiClass:(NSInteger)type
             countPerPage:(NSInteger)num
                     page:(NSInteger)page
                 andBlock:(void (^)(NSArray* placeList))block;

/**
 *根据 城市+关键字 获取兴趣点
 *@param city  城市
 *@param key   关键字
 *@param block 回调接口
 */
+ (void)placeWithCity:(NSString*)city
                  key:(NSString*)key
             andBlock:(void (^)(NSArray* placeList))block;

/**
 *周边查询接口
 *@param keyword 搜索关键字
 *@param centerCoords 检索的中心点，经纬度
 *@param radius 周边检索半径
 *@param block  回调接口
 */
+ (void)poiSearchNearByUseLocalMap:(NSString *)keyword
                          location:(CLLocationCoordinate2D)centerCoords
                            radius:(CGFloat)radius
                          andBlock:(void (^)(NSArray* placeList))block;

/// 检索模块的Delegate
@property (nonatomic, assign) id<ALDPoiSearchDelegate> delegate;

/**
 *城市POI检索(使用立得空间地图数据)
 *异步函数，返回结果在ALDPoiSearchDelegate的onGetPoiResult通知
 *@param ac     行政区编号
 *@param keyword  关键字或首字母或拼音
 *@return 成功返回YES，否则返回NO
 */
- (BOOL)poiSearchInCityWithAC:(NSInteger)ac keyword:(NSString *)keyword;

/**
 *城市POI检索(使用搜狗地图数据)
 *异步函数，返回结果在ALDPoiSearchDelegate的onGetPoiResult通知
 *@param city  城市名
 *@param keyword 搜索关键字
 *@return 成功返回YES，否则返回NO
 */
- (BOOL)poiSearchInCity:(NSString *)city key:(NSString *)keyword;

/**
 *根据范围和检索词发起范围检索
 *异步函数，返回结果在ALDPoiSearchDelegate的onGetPoiResult通知
 *@param keyword 搜索关键字
 *@param bounds 矩形区域,结构类型(ALDPoiSearchBounds)
 *@return 成功返回YES，否则返回NO
 */
- (BOOL)poiSearchInbounds:(NSString*)keyword bounds:(ALDPoiSearchBounds)bounds;

/**
 *根据中心点、半径和检索词发起周边检索(使用搜狗地图数据)
 *异步函数，返回结果在ALDPoiSearchDelegate的onGetPoiResult通知
 *@param keyword 搜索关键字
 *@param centerCoords 检索的中心点，经纬度
 *@param radius 周边检索半径
 *@return 成功返回YES，否则返回NO
 */
- (BOOL)poiSearchNearBy:(NSString*)keyword location:(CLLocationCoordinate2D)centerCoords radius:(CGFloat)radius;

/**
 *根据中心点、半径和检索词发起周边检索(使用苹果自带地图数据)
 *异步函数，返回结果在ALDPoiSearchDelegate的onGetPoiResult通知
 *@param keyword 搜索关键字
 *@param centerCoords 检索的中心点，经纬度
 *@param radius 周边检索半径
 *@return 成功返回YES，否则返回NO
 */
- (BOOL)poiSearchUseLocalMap:(NSString *)keyword location:(CLLocationCoordinate2D)centerCoords radius:(CGFloat)radius;

@end

///搜索delegate，用于获取搜索结果
@protocol ALDPoiSearchDelegate<NSObject>
@optional
/**
 *返回POI搜索结果
 *@param searcher 搜索对象
 *@param poiResult 搜索结果列表,成员类型为ALDPoiSearchResultObject
 *@param errorCode 错误号
 */
- (void)onGetPoiResult:(NSString *)searcher result:(NSArray *)poiResult errorCode:(NSError *)errorCode;

@end
