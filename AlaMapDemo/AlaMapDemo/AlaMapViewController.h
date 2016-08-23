//
//  AlaMapViewController.h
//  AlaMapDemo
//
//  Created by Qian JX on 16/8/16.
//  Copyright © 2016年 zfsoft. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <ALDMapKit/ALDMapKit.h>

@interface AlaMapViewController : UIViewController<ALDMapViewDelegate>
@property (nonatomic, retain) ALDMapView *myMapView;
@property (nonatomic, retain) UISearchBar *searchBar;
@property (nonatomic, retain) UISearchController *searchController;
@end
