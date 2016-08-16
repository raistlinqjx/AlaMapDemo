//
//  ALDPathRecordManager.h
//  ALDMapKit
//
//  Created by tvMac on 15/12/5.
//  Copyright © 2015年 edushi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

/**演示模式播放速率模式
 *DEMO_RECORD_SPEED_SLOW       - 慢速播放－间隔4秒
 *DEMO_RECORD_SPEED_NORMAL     - 正常播放－间隔2秒
 *DEMO_RECORD_SPEED_FAST       - 快速播放－间隔1秒
 */
typedef enum {
    DEMO_RECORD_SPEED_SLOW = 0,   ///<慢速播放－间隔4秒
    DEMO_RECORD_SPEED_NORMAL,     ///<正常播放－间隔2秒
    DEMO_RECORD_SPEED_FAST        ///<快速播放－间隔1秒
}DEMO_RECORD_SPEED_ENUM;

///轨迹记录delegate
@protocol ALDPathRecordDelegate<NSObject>
@optional
- (void)updatePathWithLocations:(NSArray *)locations;
- (void)autoEndPathRecord;
@end

///运动轨迹记录
@interface ALDPathRecordManager : NSObject

/// 检索模块的Delegate
@property (nonatomic, assign) id<ALDPathRecordDelegate> delegate;
/// 演示模式播放速率
@property (nonatomic, assign) NSInteger speedMode;


/**
 *开始模拟导航
 * @param routes 模拟路径
 */
- (void)startDemoRecord:(NSArray *)routes;

/**
 *暂停/再开模拟导航
 */
- (void)pauseDemoRecord;

/**
 *停止模拟导航
 */
- (void)stopDemoRecord;

/**
 *开始记录轨迹
 */
- (void)startRecord;

/**
 *停止记录轨迹
 */
- (void)stopRecord;

/**
 *保存记录轨迹
 */
- (void)saveRecord;

/**
 * 获取所有轨迹记录
 * @return 轨迹记录数组
 */
- (NSArray*)getAllPathRecords;

/**
 * 删除一个轨迹记录
 * @param record 轨迹记录
 * @return 成功返回YES，失败返回NO
 */
- (BOOL)deletePathRecord:(NSDictionary *)record;

/**
 * 清空所有轨迹记录
 */
- (void)clearAllPathRecords;

@end
