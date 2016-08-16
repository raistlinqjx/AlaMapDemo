//
//  ALDRouteSearchManger.h
//  ALDMapKit
//
//  Created by Wengys on 15/3/5.
//  Copyright (c) 2015年 edushi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ALDRouteResultObject.h"
#import "ALDNaviResultObject.h"

/**路径检索方式
 *SEARCHTYPE_MKMAP      - 苹果地图
 *SEARCHTYPE_SOUGOUMAP  - 搜狗地图
 *SEARCHTYPE_LIDE       - 立得空间
 *SEARCHTYPE_GAODE      - 高德地图
 */
typedef enum {
    SEARCHTYPE_MKMAP = 0,   ///<苹果地图
    SEARCHTYPE_SOUGOUMAP,   ///<搜狗地图
    SEARCHTYPE_LIDE,        ///<立得空间
    SEARCHTYPE_GAODE        ///<高德地图
}SEARCHTYPE_ENUM;

@protocol ALDRouteSearchDelegate;

///路径搜索服务
@interface ALDRouteSearchManger : NSObject

/**
 *公交换乘(经纬度)
 *@param ac     行政区编号
 *@param fromCoordinate  起点经纬度
 *@param toCoordinate    终点经纬度
 *@param mode   换乘模式。1 少换乘；2 较快捷；3 少步行
 *@param block  回调接口
 */
+ (void)transitSearch:(NSInteger)ac
                begin:(CLLocationCoordinate2D)fromCoordinate
                  end:(CLLocationCoordinate2D)toCoordinate
                 mode:(NSInteger)mode
             andBlock:(void (^)(ALDNaviResultObject* result))block;

/**
 *公交换乘(地址名称)
 *@param ac     行政区编号
 *@param startPosition  起点名称
 *@param endPosition    终点名称
 *@param mode   换乘模式。1 少换乘；2 较快捷；3 少步行
 *@param block  回调接口
 */
+ (void)transitSearch:(NSInteger)ac
                start:(NSString *)startPosition
                  end:(NSString *)endPosition
                 mode:(NSInteger)mode
             andBlock:(void (^)(ALDNaviResultObject* result))block;

/**
 *驾车导航(经纬度)
 *@param angle  角度
 *@param fromCoordinate  起点经纬度
 *@param toCoordinate    终点经纬度
 *@param mode   导航模式。0 推荐路线；1 最短路程；2 少走高速
 *@param block  回调接口
 */
+ (void)drivingSearch:(NSInteger)angle
                begin:(CLLocationCoordinate2D)fromCoordinate
                  end:(CLLocationCoordinate2D)toCoordinate
                 mode:(NSInteger)mode
             andBlock:(void (^)(ALDNaviResultObject* result))block;

/**
 *驾车导航(地址名称)
 *@param angle  角度
 *@param startPosition  起点名称
 *@param endPosition    终点名称
 *@param mode   导航模式。0 推荐路线；1 最短路程；2 少走高速
 *@param block  回调接口
 */
+ (void)drivingSearch:(NSInteger)angle
                start:(NSString *)startPosition
                  end:(NSString *)endPosition
                 mode:(NSInteger)mode
             andBlock:(void (^)(ALDNaviResultObject* result))block;

/**
 *步行导航(经纬度)
 *@param angle  角度
 *@param fromCoordinate  起点经纬度
 *@param toCoordinate    终点经纬度
 *@param mode   导航模式。0 推荐路线；1 最短路程；2 少走高速
 *@param block  回调接口
 */
+ (void)walkingSearch:(NSInteger)angle
                begin:(CLLocationCoordinate2D)fromCoordinate
                  end:(CLLocationCoordinate2D)toCoordinate
                 mode:(NSInteger)mode
             andBlock:(void (^)(ALDNaviResultObject* result))block;

/**
 *步行导航(地址名称)
 *@param angle  角度
 *@param startPosition  起点名称
 *@param endPosition    终点名称
 *@param mode   导航模式。0 推荐路线；1 最短路程；2 少走高速
 *@param block  回调接口
 */
+ (void)walkingSearch:(NSInteger)angle
                start:(NSString *)startPosition
                  end:(NSString *)endPosition
                 mode:(NSInteger)mode
             andBlock:(void (^)(ALDNaviResultObject* result))block;

/// 检索模块的Delegate
@property (nonatomic, assign) id<ALDRouteSearchDelegate> delegate;

/**
 *根据地理坐标获取路径信息
 *异步函数，返回结果在ALDRouteSearchDelegate的-onGetRouteResult:errorCode:通知
 *@param fromCoordinate 检索的起点地理坐标(经纬度)
 *@param toCoordinate 检索的终点地理坐标(经纬度)
 *@param type 路径检索方式
 *@return 成功返回YES，否则返回NO
 */
- (BOOL)findRoutesFrom:(CLLocationCoordinate2D)fromCoordinate to:(CLLocationCoordinate2D)toCoordinate type:(SEARCHTYPE_ENUM)type;

@end

///路线搜索delegate，用于获取路线搜索结果
@protocol ALDRouteSearchDelegate<NSObject>
@optional
/**
 *返回路径搜索结果
 *@param result 搜索结果
 *@param error 错误号
 */
- (void)onGetRouteResult:(ALDRouteResultObject *)result errorCode:(NSError *)error;

@end
