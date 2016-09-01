//
//  SearchTableVC.h
//  GaoDeDemo
//
//  Created by GAO on 16/8/3.
//  Copyright © 2016年 GAO. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <ALDMapKit/ALDMapKit.h>
@interface SearchTableVC : UITableViewController

@property(nonatomic, strong) NSMutableArray * searchResult;

@property(nonatomic, strong) ALDMapView      * myMapView;
@end
