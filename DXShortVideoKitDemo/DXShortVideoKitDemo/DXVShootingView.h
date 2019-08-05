//
//  DXVShootingView.h
//  DXShortVideoKitDemo
//
//  Created by huDingfeng on 2019/8/5.
//  Copyright © 2019 hudingfeng. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "DXVVideoModel.h"
typedef NS_ENUM(NSInteger, DTRecordState) {
    DTRecordStateInit,
    DTRecordStateRecording,
    DTRecordStatePause,
    DTRecordStateCombining,
    DTRecordStateRePlay,
};

typedef NS_ENUM(NSInteger, DTTorchState) {
    DTTorchClose = 0,
    DTTorchOpen,
    DTTorchAuto,
};
NS_ASSUME_NONNULL_BEGIN

@interface DXVShootingView : UIView
@property (nonatomic) NSInteger recordState;
@property (nonatomic) NSInteger torchType;
@property (nonatomic, strong) DXVVideoModel *videoModel;

- (instancetype)initWithFrame:(CGRect)frame;

- (void)startRecord;
- (void)pauseRecord;
- (void)finishVideoRecord;

- (void)selectLastDeletePart;
- (void)didDeleteLastPart;
- (void)resetRecord;

- (void)switchTorch;
- (void)switchCamera;

@end

NS_ASSUME_NONNULL_END
