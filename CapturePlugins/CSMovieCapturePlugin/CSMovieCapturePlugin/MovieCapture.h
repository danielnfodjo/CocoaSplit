//
//  MovieCapture.h
//  CocoaSplit
//
//  Created by Zakk on 8/26/14.
//  Copyright (c) 2014 Zakk. All rights reserved.
//

#import "CSCaptureBase.h"
#import "CSPcmPlayer.h"
#import "CAMultiAudioPCM.h"
#import "CSPluginServices.h"
#import "CSIOSurfaceLayer.h"

#import <AVFoundation/AVFoundation.h>


@interface MovieCapture : CSCaptureBase <CSCaptureSourceProtocol>
{
    CAMultiAudioPCM *_bufferPCM;
    dispatch_queue_t _audioQueue;
    
}



@property (strong) CSPcmPlayer *pcmPlayer;
@property (assign) AudioStreamBasicDescription audioFormat;
@property (strong) AVQueuePlayer *avPlayer;
@property (strong) AVPlayerItemVideoOutput *avOutput;
@property (strong) NSURL *currentMedia;
@property (strong) NSString *playPauseTitle;
@property (assign) double currentMovieTime;
@property (readonly) NSString *currentMovieTimeString;
@property (readonly) NSString *movieDurationString;
@property (readonly) double movieDuration;
@property (readonly) NSArray *movieQueue;


@property (strong) id timeToken;


-(void)chooseMedia;

-(void)copyAudioBufferList:(AudioBufferList *)bufferList;

-(void) nextMovie;
-(void)removeQueueItems:(NSIndexSet *)movieIndexes;
-(void)preallocateAudioBuffers:(CMItemCount)frameCount audioFormat:(const AudioStreamBasicDescription *)audioFormat;
-(void) playAudioBuffer:(AudioBufferList *)buffer;


@end
