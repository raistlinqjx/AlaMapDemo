//
//  ALDBicycleSearchManager.h
//  ALDMapKit
//
//  Created by tvMac on 15/11/8.
//  Copyright © 2015年 edushi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "ALDSearchCommonHeader.h"

@protocol ALDBicycleSearchDelegate;

///自行车检索服务
@interface ALDBicycleSearchManager : NSObject

///检索模块的Delegate
@property (nonatomic, assign) id<ALDBicycleSearchDelegate> delegate;

/**
 *城市关键字检索
 *异步函数，返回结果在ALDBicycleSearchDelegate的onGetBicycleResult通知
 *@param city  城市名
 *@param keyword 搜索关键字
 *@return 成功返回YES，否则返回NO
 */
- (BOOL)bicycleSearchInCity:(NSString *)city key:(NSString *)keyword;

/**
 *根据屏幕范围进行区域检索
 *异步函数，返回结果在ALDBicycleSearchDelegate的onGetBicycleResult通知
 *@param bounds 矩形区域,结构类型(ALDAreaSearchBounds)
 *@return 成功返回YES，否则返回NO
 */
- (BOOL)bicycleSearchInbounds:(ALDAreaSearchBounds)bounds;

/**
 *根据中心点、半径进行周边检索
 *异步函数，返回结果在ALDBicycleSearchDelegate的onGetBicycleResult通知
 *@param centerCoords 检索的中心点，经纬度
 *@param radius 周边检索半径,单位米
 *@return 成功返回YES，否则返回NO
 */
- (BOOL)bicycleSearchNearBy:(CLLocationCoordinate2D)centerCoords radius:(float)radius;

@end

///搜索delegate，用于获取搜索结果
@protocol ALDBicycleSearchDelegate<NSObject>
@optional
/**
 *返回POI搜索结果
 *@param searcher 搜索对象
 *@param result 搜索结果列表,成员类型为
 *@param error 错误号
 */
- (void)onGetBicycleResult:(NSString *)searcher result:(NSArray *)result error:(NSError *)error;

@end
