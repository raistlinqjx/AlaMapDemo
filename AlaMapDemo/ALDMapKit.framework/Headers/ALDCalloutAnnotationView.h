//
//  ALDCalloutAnnotationView.h
//  ALDMapKit
//
//  Created by Wengys on 15/4/17.
//  Copyright (c) 2015年 edushi. All rights reserved.
//

#import <UIKit/UIKit.h>

/// 标注气泡视图
@interface ALDCalloutAnnotationView : UIView

/// 气泡视图
@property (nonatomic,retain)UIView *contentView;

/// 锚点偏移量
@property (nonatomic,assign)CGFloat adjustX;

/**
 *初始化气泡视图
 */
- (id)initWithArrow;

@end
