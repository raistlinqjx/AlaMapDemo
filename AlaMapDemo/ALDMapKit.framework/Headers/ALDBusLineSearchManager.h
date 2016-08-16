//
//  ALDBusLineSearchManager.h
//  ALDMapKit
//
//  Created by Wengys on 15/3/5.
//  Copyright (c) 2015年 edushi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ALDBusLineDetailObject.h"
#import "ALDBusResultObject.h"

@protocol ALDBusLineSearchDelegate;

///公交搜索服务
@interface ALDBusLineSearchManager : NSObject

/**
 *公交线路查询(线路号)
 *@param ac     行政区编号
 *@param line   线路号
 *@param block  回调接口
 */
+ (void)busLineInCity:(NSInteger)ac
                 line:(NSString *)line
             andBlock:(void (^)(ALDBusLineResultObject* result))block;

/**
 *公交线路查询(线路ID)
 *@param ac     行政区编号
 *@param lineId 线路ID编号
 *@param block  回调接口
 */
+ (void)busLineInCity:(NSInteger)ac
               lineId:(NSInteger)lineId
             andBlock:(void (^)(ALDBusLineResultObject* result))block;

/**
 *公交站点ID查询
 *@param ac     行政区编号
 *@param stopId 站点ID
 *@param block  回调接口
 */
+ (void)busStopInCity:(NSInteger)ac
               stopId:(NSInteger)stopId
             andBlock:(void (^)(ALDBusStopResultObject* result))block;

/**
 *周边站点查询
 *@param coords 中心点经纬度
 *@param range  查询范围，半径，单位为米
 *@param block  回调接口
 */
+ (void)busStopNearBy:(CLLocationCoordinate2D)coords
                range:(NSInteger)range
             andBlock:(void (^)(NSArray* placeList))block;

/**
 *公交站点关键字查询
 *@param ac     行政区编号
 *@param input  关键字或首字母或拼音
 *@param block  回调接口
 */
+ (void)busSearchCity:(NSInteger)ac
                input:(NSString *)input
             andBlock:(void (^)(NSArray* placeList))block;

/// 检索模块的Delegate
@property (nonatomic, assign) id<ALDBusLineSearchDelegate> delegate;

/**
 *公交线站查询
 *异步函数，返回结果在ALDBusLineSearchDelegate的-onGetBusInfo:result:errorCode:通知
 *@param line 线路番号/名称
 *@return 成功返回YES，否则返回NO
 */
- (BOOL)busInfoSearch:(NSString *)line;

/**
 *公交线路信息查询
 *异步函数，返回结果在ALDBusLineSearchDelegate的-onGetBusDetailResult:result:errorCode:通知
 *@param lineID 公交线路ID
 *@return 成功返回YES，否则返回NO
 */
- (BOOL)lineDetailSearch:(NSString *)lineID;

/**
 *公交站点信息查询
 *异步函数，返回结果在ALDBusLineSearchDelegate的-onGetBusStationResult:result:errorCode:通知
 *@param stationID 公交站点ID
 *@return 成功返回YES，否则返回NO
 */
- (BOOL)stationInfoSearch:(NSString *)stationID;

@end

///搜索delegate，用于获取搜索结果
@protocol ALDBusLineSearchDelegate<NSObject>
@optional
/**
 *返回公交信息搜索结果
 *@param searcher 搜索对象
 *@param result 搜索结果
 *@param error 错误号
 */
- (void)onGetBusInfo:(NSString *)searcher result:(NSArray *)result errorCode:(NSError *)error;

/**
 *返回公交线路信息搜索结果
 *@param searcher 搜索对象
 *@param busLineResult 搜索结果
 *@param error 错误号
 */
- (void)onGetBusDetailResult:(NSString *)searcher result:(ALDBusLineDetailObject *)busLineResult errorCode:(NSError *)error;

/**
 *返回公交站点信息搜索结果
 *@param searcher 搜索对象
 *@param result 搜索结果
 *@param error 错误号
 */
- (void)onGetBusStationResult:(NSString *)searcher result:(NSArray *)result errorCode:(NSError *)error;

@end