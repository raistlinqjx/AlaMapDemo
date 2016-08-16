//
//  ALDAnimateObject.h
//  ALDMapKit
//
//  Created by Wengys on 15/3/18.
//  Copyright (c) 2015年 edushi. All rights reserved.
//

#import <Foundation/Foundation.h>

///动画存储对象
@interface ALDAnimateObject : NSObject

/// 动画图片列表
@property (nonatomic, strong) NSArray *imageArray;
/// 为图象的一个循环。 默认值是图象的编号* 1/30秒(即30 fps)
@property (nonatomic) NSTimeInterval animationDuration;

/**
 *初始化动画对象
 *@param imageArray 动画图片列表
 *@param duration 动画循环周期(单位秒)
 */
- (id)initWithArray:(NSArray *)imageArray duration:(NSTimeInterval)duration;

@end
