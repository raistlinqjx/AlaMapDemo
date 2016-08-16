//
//  ALDAnimatedAnnotationView.h
//  ALDMapKit
//
//  Created by Wengys on 15/1/28.
//  Copyright (c) 2015年 edushi. All rights reserved.
//

#import <MapKit/MapKit.h>
#import "ALDAnimateObject.h"

/// 动画标注视图
@interface ALDAnimatedAnnotationView : MKAnnotationView

/// 动画图片列表对象
@property (nonatomic, strong) ALDAnimateObject *annotationImages;
/// 动画显示视图
@property (nonatomic, strong) UIImageView *annotationImageView;
/// 从天上掉下效果
@property (nonatomic) BOOL animatesDrop;

@end
