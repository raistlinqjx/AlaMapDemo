//
//  ALDDownloadObject.h
//  ALDMapKit
//
//  Created by apple on 15/11/4.
//  Copyright © 2015年 edushi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ALDMapObject.h"

/**下载状态
 *DOWNLOAD_STATE_NONE    - 未下载
 *DOWNLOAD_STATE_START   - 开始下载
 *DOWNLOAD_STATE_STOP    - 停止下载
 *DOWNLOAD_STATE_WAIT    - 等待下载
 *DOWNLOAD_STATE_DONE    - 完成下载
 */
typedef enum {
    DOWNLOAD_STATE_NONE = 0,     ///<未下载
    DOWNLOAD_STATE_START,        ///<开始下载
    DOWNLOAD_STATE_STOP,         ///<停止下载
    DOWNLOAD_STATE_WAIT,         ///<等待下载
    DOWNLOAD_STATE_DONE          ///<完成下载
}DOWNLOAD_STATE_ENUM;

///地图离线下载数据对象
@interface ALDDownloadObject : NSObject

///地图显示等级(默认11～18)
@property (nonatomic, assign)NSInteger level;
///瓦块行号
@property (nonatomic, assign)NSInteger px;
///瓦块列号
@property (nonatomic, assign)NSInteger py;
///经度
@property (nonatomic, assign)double longitude;
///纬度
@property (nonatomic, assign)double latitude;
///下载状态
@property (nonatomic, assign)NSInteger state;
///包大小
@property (nonatomic, assign)long long size;
///下载进度
@property (nonatomic, assign)NSInteger percentage;
///字典对象，plist保存用
@property (nonatomic, strong) NSDictionary *dictionaryData;

/**
 *初始化地图离线下载数据对象
 *@param object 地图数据对象
 */
- (id)initWithMapObject:(ALDMapObject *)object;

@end
