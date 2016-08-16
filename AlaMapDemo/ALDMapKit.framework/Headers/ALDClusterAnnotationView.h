//
//  ALDClusterAnnotationView.h
//  ALDMapKit
//
//  Created by Wengys on 15/2/4.
//  Copyright (c) 2015年 edushi. All rights reserved.
//

#import <MapKit/MapKit.h>

/// 组标注视图
@interface ALDClusterAnnotationView : MKAnnotationView

///背景图片
@property (nonatomic,readonly,retain) UIImage* background;
///子标注个数
@property (nonatomic, retain) NSString *count;

/// 图片背景视图
@property (nonatomic, strong) UIImageView *backgroundImageView;
/// 标注文本视图
@property (nonatomic, strong) UILabel *countLabel;
/// 从天上掉下效果
@property (nonatomic) BOOL animatesDrop;

@end
