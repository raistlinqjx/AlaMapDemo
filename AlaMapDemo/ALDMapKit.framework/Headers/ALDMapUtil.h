//
//  ALDMapUtil.h
//  ALDMapKit
//
//  Created by Wengys on 15/1/15.
//  Copyright (c) 2015年 edushi. All rights reserved.
//

#import <Foundation/Foundation.h>

///地图包工具类
@interface ALDMapUtil : NSObject

/**
 *初始化缓存文件夹
 */
+(void)initDataFileDir;

/**
 *是否存在缓存文件夹
 *@return 是否存在
 */
+(BOOL)isDataFileDirExist;

/**
 *删除所有缓存文件
 */
+(void)deleteAllDataFile;

/**
 *获取测试用经纬度配置文件
 *@return 配置文件绝对路径
 */
+(NSString*)getTestLocationFilePath;

/**
 *获取收藏点配置文件
 *@return 配置文件绝对路径
 */
+(NSString*)getFavPoiFilePath;

/**
 *获取轨迹记录文件
 *@return 轨迹记录文件绝对路径
 */
+(NSString*)getPathRecordFilePath;

/**
 *获取足迹记录文件
 *@return 足迹记录文件绝对路径
 */
+(NSString*)getTraceRecordFilePath;

/**
 *获取地图缓存文件总大小，单位MB
 *@return 该城市地图文件包大小
 */
+(double)getMapDiskSize;

/**
 *获取磁盘总空间大小
 *@return 磁盘总空间大小
 */
+(NSString *)totalDiskSpace;

/**
 *获取磁盘剩余空间大小
 *@return 磁盘剩余空间大小
 */
+(NSString *)freeDiskSpace;

/**
 *获取磁盘使用空间大小
 *@return 磁盘使用空间大小
 */
+(NSString *)usedDiskSpace;

@end
