//
//  SearchResultCell.m
//  GaoDeDemo
//
//  Created by GAO on 16/8/4.
//  Copyright © 2016年 GAO. All rights reserved.
//

#import "SearchResultCell.h"

@implementation SearchResultCell



- (instancetype)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if(!self)
    {
        return nil;
    }
    
    
    return self;
}
- (void)awakeFromNib {
    [super awakeFromNib];
    // Initialization code
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated {
    [super setSelected:selected animated:animated];

    // Configure the view for the selected state
}

@end
