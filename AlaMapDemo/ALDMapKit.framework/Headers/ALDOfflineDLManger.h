//
//  ALDOfflineDLManger.h
//  ALDMapKit
//
//  Created by Wengys on 15/2/4.
//  Copyright (c) 2015年 edushi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "ALDMapObject.h"

///离线下载设置
@interface ALDOfflineDLOption : NSObject

///地图等级
@property (nonatomic, retain) NSString *mapLevel;
///中心位置经纬度
@property (nonatomic, assign) CLLocationCoordinate2D coordinate;
///左上角瓦块列号
@property (nonatomic, assign) NSInteger leftTopCol;
///左上角瓦块行号
@property (nonatomic, assign) NSInteger leftTopRow;
///右下角瓦块列号
@property (nonatomic, assign) NSInteger rightBottomCol;
///右下角瓦块行号
@property (nonatomic, assign) NSInteger rightBottomRow;

@end

@protocol ALDOfflineMapDelegate;

/// 离线下载管理
@interface ALDOfflineDLManger : NSObject

/// 离线下载manager的delegate
@property (nonatomic, assign) id<ALDOfflineMapDelegate> delegate;

/**
 *获取离线地图下载对象
 *@param obj 地图瓦块对象
 *@return 下载参数，成员ALDOfflineDLOption
 */
- (NSArray *)prepareWithMapObject:(ALDMapObject *)obj;

/**
 *扫描已下载的离线地图
 *@param options 下载参数，成员ALDOfflineDLOption
 */
- (void)scan:(NSArray *)options;

/**
 *启动下载指定中心经纬度的离线地图
 *@param options 下载参数，成员ALDOfflineDLOption
 */
- (void)start:(NSArray *)options;

/**
 *暂停下载指定中心经纬度的离线地图
 */
- (void)pause;

/**
 *删除下载指定中心经纬度的离线地图
 *@param options 下载参数，成员ALDOfflineDLOption
 */
- (void)remove:(NSArray *)options;

/**
 *返回推荐地点列表
 *@return 推荐地点列表
 */
+ (NSArray*)getHotList;

/**
 *返回常去地点列表
 *@return 常去地点列表
 */
+ (NSArray*)getOfflineList;

/**
 *删除所有下载的离线地图
 */
+ (void)removeAllMaps;

/**
 *删除所有下载的离线地图
 *@param block 回调
 */
+ (void)removeAllMapsWithBlock:(void (^)(BOOL finished))block;

/**
 *获取地图缓存文件总大小，单位MB
 *@param block 回调
 */
+ (void)getMapDiskSizeWithBlock:(void (^)(double totalSize))block;

@end

///离线地图delegate，用于获取通知
@protocol ALDOfflineMapDelegate<NSObject>
@optional
/**
 *返回下载进度
 *@param percentage 下载进度
 */
- (void)updateUI:(NSInteger)percentage;

/**
 *返回下载速度
 *@param speed 下载速度(kb/s)
 */
- (void)downloadSpeed:(NSInteger)speed;

/**
 *返回错误信息
 *@param error 错误信息
 */
- (void)downloadError:(NSError *)error;

/**
 *返回下载完成时包大小
 *@param bytes 包大小(byte)
 */
- (void)downloadFinished:(long long)bytes;

@end
