//
//  CAMultiAudioEngine.h
//  CocoaSplit
//
//  Created by Zakk on 11/15/14.
//  Copyright (c) 2014 Zakk. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CAMultiAudio.h"


/* our default graph setup looks like this:
 
 
 
 silentNode -> encodeMixer -> previewMixer -> defaultOutputNode
 The outout of encodeMixer is tapped to provide the audio for the outgoing stream
*/
@interface CAMultiAudioEngine : NSObject

@property (strong) CAMultiAudioGraph *graph;
@property (strong) CAMultiAudioMixer *previewMixer;
@property (strong) CAMultiAudioPCMPlayer *silentNode;
@property (strong) CAMultiAudioDefaultOutput *defaultOutputNode;
@property (strong) NSMutableArray *audioInputs;
@property (strong) CAMultiAudioMixer *encodeMixer;
//@property (strong) CSAacEncoder *encoder;
@property (assign) UInt32 sampleRate;




-(void)attachInput:(CAMultiAudioNode *)input;
-(instancetype)initWithSamplerate:(UInt32)sampleRate;


@end
