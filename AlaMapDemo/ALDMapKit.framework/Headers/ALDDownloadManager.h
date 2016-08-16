//
//  ALDDownloadManager.h
//  ALDMapKit
//
//  Created by tvMac on 15/3/29.
//  Copyright (c) 2015年 edushi. All rights reserved.
//

#import <Foundation/Foundation.h>

/**网络连接状态
 *NETWORK_STATUS_DISCONNECT - 断开
 *NETWORK_STATUS_WIFI       - WI-FI
 *NETWORK_STATUS_WWAN       - 2G/3G/4G
 */
typedef enum : NSInteger {
    NETWORK_STATUS_DISCONNECT = 0,  ///<断开
    NETWORK_STATUS_WIFI,            ///<WI-FI
    NETWORK_STATUS_WWAN             ///<2G/3G/4G
} NETWORK_STATUS_ENUM;

/// 地图下载管理
@interface ALDDownloadManager : NSObject

///仅Wi-Fi环境下允许下载地图
@property (nonatomic, assign)BOOL wifiOnly;
///当前网络状态
@property (nonatomic, assign)NETWORK_STATUS_ENUM networkStatus;

/**
 *初始化（单实例）
 *@return 单实例
 */
+ (ALDDownloadManager *)sharedManager;

/**
 *启动引擎
 *@param key 申请的有效key
 *@param code 安全码bundle identifier
 *@return 成功:YES／失败:NO
 */
- (BOOL)start:(NSString*)key code:(NSString *)code;

/**
 *停止引擎
 *@return 成功:YES／失败:NO
 */
- (BOOL)stop;

/**
 *获取授权结果
 *@return 授权成功:0／授权失败:-1／未授权:-2
 */
- (int)getAuthorizedState;

/**
 *从服务器获取地图版本信息
 *@return 成功:YES／失败:NO
 */
- (BOOL)getMapVersion;

/**
 *获取地图更新列表
 *@return 地图更新列表
 */
- (NSArray *)getMapUpdateList;

/**
 *根据瓦片行列号和地图等级获取地图区域编号
 *@param x 地图瓦片行号
 *@param y 地图瓦片列号
 *@param level 地图等级
 *@return 地图区域编号
 */
- (NSString *)convertMapKeyWithPos:(NSInteger)x andY:(NSInteger)y level:(NSInteger)level;

/**
 *根据地图区域编号获取该区域地图版本号
 *@param mapKey 地图区域编号
 *@return 该区域地图版本号
 */
- (NSInteger)getMapVersionWithKey:(NSString *)mapKey;

/**
 *根据瓦片名称和地图等级生成下载url
 *@param name 地图瓦片名称
 *@param level 地图等级
 *@param useSimpleMap 使用二维地图
 *@return 瓦块下载url
 */
- (NSURL *)urlWithName:(NSString *)name andLevel:(NSString *)level useSimpleMap:(BOOL)useSimpleMap;

/**
 *根据瓦片名称和地图等级获取下载绝对路径
 *@param name 地图瓦片名称
 *@param level 地图等级
 *@param useSimpleMap 使用二维地图
 *@return 瓦块保存绝对路径
 */
- (NSString *)getFilePath:(NSString *)name level:(NSString *)level useSimpleMap:(BOOL)useSimpleMap;

/**
 *初始化地图文件缓存池
 */
- (void)initAllMapFolder;

@end
