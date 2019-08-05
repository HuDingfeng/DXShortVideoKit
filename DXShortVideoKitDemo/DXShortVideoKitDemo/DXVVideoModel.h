//
//  DXVVideoModel.h
//  DXShortVideoKitDemo
//
//  Created by huDingfeng on 2019/8/5.
//  Copyright © 2019 hudingfeng. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import <AssetsLibrary/AssetsLibrary.h>
NS_ASSUME_NONNULL_BEGIN


typedef void (^combineVideoCompleteHandler) ();
@interface VideoPartModel : NSObject

@property(nonatomic, strong) NSString *partName;
@property(nonatomic, strong) NSURL *partTempFileUrl;
@property(nonatomic) CMTime partDuration;

@end



@interface DXVVideoModel : NSObject
@property (nonatomic, strong) combineVideoCompleteHandler combineCompleteHandler;
@property(nonatomic, strong) NSMutableArray<VideoPartModel*> *videoParts;

@property(nonatomic, assign) CGSize videoSize;
@property(nonatomic, strong) NSString *localFileDirectory;

@property(nonatomic, strong) NSString *videoName;
@property(nonatomic, strong) NSURL *videoTempFileUrl;
@property(nonatomic, strong) NSURL *videoExportUrl;

@property(assign) CGFloat minRecordTime;
@property(assign) CGFloat maxRecordTime;

@property(nonatomic, strong) NSURL *currentVideoPartTempFileUrl;
@property(nonatomic, strong) NSURL *currentVideoPartExportUrl;

@property(nonatomic) CMTime duration;

- (instancetype)init;

- (void)appendNewPartVideoModel;

- (void)deleteLastVideoPart;

- (void)resetVideoParts;

- (void)combineVideosToSandBoxWithCompleteHandler:(combineVideoCompleteHandler) completeHandler;
@end

NS_ASSUME_NONNULL_END
