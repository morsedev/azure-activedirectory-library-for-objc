// Created by Boris Vidolov on 10/17/13.
// Copyright © Microsoft Open Technologies, Inc.
//
// All Rights Reserved
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// THIS CODE IS PROVIDED *AS IS* BASIS, WITHOUT WARRANTIES OR CONDITIONS
// OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION
// ANY IMPLIED WARRANTIES OR CONDITIONS OF TITLE, FITNESS FOR A
// PARTICULAR PURPOSE, MERCHANTABILITY OR NON-INFRINGEMENT.
//
// See the Apache License, Version 2.0 for the specific language
// governing permissions and limitations under the License.

#import <Foundation/Foundation.h>
#import <ADALiOS/ADUserInformation.h>
#import <ADALiOS/ADTokenCacheStoreKey.h>
#import <ADALiOS/ADAuthenticationError.h>

/*! Contains all cached elements for a given request for a token.
    Objects of this class are used in the key-based token cache store.
    See the key extraction function for details on how the keys are constructed. */
@interface ADTokenCacheStoreItem : NSObject<NSCopying , NSSecureCoding>

/*! Applicable resource */
@property NSString* resource;

@property NSString* authority;

@property NSString* clientId;

@property NSString* accessToken;

@property NSString* accessTokenType;

@property NSString* refreshToken;

@property NSDate* expiresOn;

@property ADUserInformation* userInformation;

@property NSString* tenantId;

/*! Obtains a key to be used for the internal cache from the full cache item.
 @param error: if a key cannot be extracted, the method will return nil and if this parameter is not nil,
 it will be filled with the appropriate error information.*/
-(ADTokenCacheStoreKey*) extractKeyWithError: (ADAuthenticationError* __autoreleasing *) error;

/*! Compares expiresOn with the current time. If expiresOn is not nil, the function returns the
 comparison of expires on and the current time. If expiresOn is nil, the function returns NO,
 so that the cached token can be tried first.*/
-(BOOL) isExpired;

/*! Returns YES if the user is not not set. */
-(BOOL) isEmptyUser;

/*! Verifies if the user (as defined by userId) is the same between the two items. */
-(BOOL) isSameUser: (ADTokenCacheStoreItem*) other;

@end
