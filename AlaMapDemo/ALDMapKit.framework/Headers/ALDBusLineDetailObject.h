//
//  ALDBusLineDetailObject.h
//  ALDMapKit
//
//  Created by Wengys on 15/3/6.
//  Copyright (c) 2015年 edushi. All rights reserved.
//

#import <Foundation/Foundation.h>

///线路的票价，长度，收费标准等信息
@interface ALDBusLineDetailInfo : NSObject

///线路总的长度
@property (nonatomic, retain)NSString* linelength;
///起点站首车时间
@property (nonatomic, retain)NSString* starttime;
///起点站末车时间
@property (nonatomic, retain)NSString* endtime;
///所属运营公司
@property (nonatomic, retain)NSString* filiale;
///票制计价类型
@property (nonatomic, retain)NSString* isunitarycarfare;
///标识月票是否有效
@property (nonatomic, retain)NSString* iscommutationvalid;
///单程最高票价
@property (nonatomic, retain)NSString* carfare;

@end

///具体的线路信息
@interface ALDBusLineFeature : NSObject

///聚类id，在查找详细信息中需要用到此id
@property (nonatomic, retain)NSNumber* cid;
///站点的名称
@property (nonatomic, retain)NSString* caption;
///坐标信息，坐标串中的坐标用逗号隔开，如：x,y,x,y...。
@property (nonatomic, retain)NSString* Points;
///Point元素的类型。S：点，L：线。
@property (nonatomic, retain)NSString* type;
///站点在线路中次序。例如：第一站时，stoporder就是1。
@property (nonatomic, assign)NSInteger stoporder;

@end


///线路的信息元素
@interface ALDBusLineDetailObject : NSObject

///线路的唯一标识
@property (nonatomic, readonly, retain)NSNumber* uid;
///线路的名称
@property (nonatomic, readonly, retain)NSString* name;
///具体的线路信息，成员类型为ALDBusLineFeature
@property (nonatomic, readonly, retain)NSArray* data;
///线路的票价，长度，收费标准等信息
@property (nonatomic, readonly, retain)ALDBusLineDetailInfo* DetailInfo;

/**
 *初始化公交线路信息对象
 *@param dictionary 数据对象
 */
- (id)initWithDictionary:(NSDictionary *)dictionary;

@end
