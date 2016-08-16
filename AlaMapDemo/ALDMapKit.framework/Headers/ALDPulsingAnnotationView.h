//
//  ALDPulsingAnnotationView.h
//  ALDMapKit
//
//  Created by tvMac on 15/9/12.
//  Copyright (c) 2015年 edushi. All rights reserved.
//

#import <MapKit/MapKit.h>

/// 标签标注视图
@interface ALDPulsingAnnotationView : MKAnnotationView

/// 标注点颜色，默认同MKUserLocationView
@property (nonatomic, strong) UIColor *annotationColor;

/// 扩散动画时间，默认1秒
@property (nonatomic, readwrite) NSTimeInterval pulseAnimationDuration;

/// 扩散动画间隔，默认1秒
@property (nonatomic, readwrite) NSTimeInterval delayBetweenPulseCycles;

/// 标签名称
@property (nonatomic, strong) NSString *annotationTitle;

/// 标签个数
@property (nonatomic, readwrite) NSInteger annotationCount;

/// 从天上掉下效果
@property (nonatomic) BOOL animatesDrop;

/**
 *设置标签标注
 *@param color 标注点颜色
 *@param title 标签名称
 *@param count 标签个数
 */
- (void)setupAnnotationWithColor:(UIColor *)color title:(NSString *)title count:(NSInteger)count;

@end
