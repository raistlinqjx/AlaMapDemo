//
//  ALDAnnotationView.h
//  ALDMapKit
//
//  Created by Wengys on 15/1/28.
//  Copyright (c) 2015年 edushi. All rights reserved.
//

#import <MapKit/MapKit.h>

///闪光动画播放时间
#define FLASH_ANIMATION_DURATION    1.0f

/// 图片标注视图
@interface ALDAnnotationView : MKAnnotationView

///头像图片(异步下载)
@property (nonatomic,retain) NSURL* imageURL;
///背景图片
@property (nonatomic,retain) UIImage* background;

/// 图片显示视图
@property (nonatomic, strong) UIImageView *annotationImageView;
/// 图片背景视图
@property (nonatomic, strong) UIImageView *backgroundImageView;
/// 从天上掉下效果
@property (nonatomic) BOOL animatesDrop;

/**
 *开始播放闪光动画
 */
- (void)startFlashAnimate;

/**
 *停止播放闪光动画
 */
- (void)stopFlashAnimate;

@end
