/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2016 RDK Management
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
*/
 
/**
 * @file dsHdmiIn.c
 *
 * @brief Device Settings HAL HDMI input Public API Implementation
 * for the Device Settings HDMI input interface.
 * NOTE: RaspberryPi does not have HDMI-In support and this implementation is a Dummy.
 *
 * @par Abbreviations
 * - cb:      Callback function (suffix).
 * - DS:      Device Settings.
 * - HAL:     Hardware Abstraction Layer.
 * - EDID:    Extended Display Identification Data.
 * - SPD:     Source Product Description.
 * - ARC:     Audio Return Channel.
 * - ALLM:    Auto Low Latency Mode
 * - HDMI:    High-Definition Multimedia Interface
 * - AV:      Audio-Visual
 * - HdmiIn:  HDMI Input
 *
 */

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdint.h>    
#include <stdbool.h>

#include "dsError.h"
#include "dsHdmiIn.h"
#include "dsAVDTypes.h"
#include "dsHdmiInTypes.h"
#include "dsVideoDeviceTypes.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Initializes the underlying HDMI input sub-system
 * 
 * This function must initialize the HDMI input module and any associated resources.
 *
 * @return dsError_t                    - Status
 * @retval dsERR_NONE                   - Success
 * @retval dsERR_ALREADY_INITIALIZED    - Function is already initialized
 * @retval dsERR_RESOURCE_NOT_AVAILABLE - Resources have failed to allocate
 * @retval dsERR_GENERAL                - Underlying undefined platform error
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsHdmiInTerm()
 * 
 */
dsError_t dsHdmiInInit (void)
{
    // No platform support; nothing to do here.
    return dsERR_NONE;
}

/**
 * @brief Terminates the underlying HDMI input sub-system
 * 
 * This function must terminate the HDMI input module and any associated resources.
 *
 * @return dsError_t                    - Status
 * @retval dsERR_NONE                   - Success
 * @retval dsERR_NOT_INITIALIZED        - Module is not initialised
 * @retval dsERR_GENERAL                - Underlying undefined platform error
 * 
 * 
 * @pre dsHdmiInInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsHdmiInInit()
 * 
 */
dsError_t dsHdmiInTerm (void)
{
    // No platform support; nothing to do here.
    return dsERR_NONE;
}

/**
 * @brief Gets the number of HDMI input ports on the device
 * 
 * This function gets the number of HDMI input ports on the device.
 *
 * @param[out] pNumberOfinputs  - number of HDMI input ports. 
 *                                 Please refer  ::dsHdmiInPort_t for max number of inputs. Min is 0
 * 
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported; e.g: source devices
 * @retval dsERR_OPERATION_FAILED           - The attempted operation has failed
 * 
 * @pre dsHdmiInInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 */
dsError_t dsHdmiInGetNumberOfInputs (uint8_t *pNumberOfinputs)
{
    if (NULL == pNumberOfinputs)
        return dsERR_INVALID_PARAM;
    // No HDMI-IN support.
    *pNumberOfinputs = 0;
    return dsERR_OPERATION_NOT_SUPPORTED;
}

/**
 * @brief Gets the HDMI input port status of all ports
 * 
 * This function gets the HDMI input port status.
 *
 * @param[out] pStatus  - status of the HDMI input ports. Please refer ::dsHdmiInStatus_t
 *
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported; e.g: source devices
 * @retval dsERR_OPERATION_FAILED           - The attempted operation has failed
 * 
 * @pre dsHdmiInInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 */
dsError_t dsHdmiInGetStatus (dsHdmiInStatus_t *pStatus)
{
    if (NULL == pStatus)
        return dsERR_INVALID_PARAM;
    // No HDMI-IN support.
    return dsERR_OPERATION_NOT_SUPPORTED;
}

/**
 * @brief Selects the HDMI input port as active and available for presentation
 * 
 * This function selects the HDMI input port for presentation.
 *
 * @param[in] Port              - HDMI input port to be presented.  Please refer ::dsHdmiInPort_t
 * @param[in] audioMix    	    - Flag to control the audioMix status ( @a true to enable, @a false to disable)
 * @param[in] evideoPlaneType 	- Video plane to be selected  Please refer ::dsVideoPlaneType_t
 * @param[in] topMost        	- Is this the topmost port? ( @a true for topMost port, @a false for not)
 *                                If true, the plane used by the HDMI input port is over any other video plane
 *                                If false, the plane used by the HDMI input port is under any other video plane
 *                                 this is applicable irrespective of HDMI input port is playing either in primary or secondary
 *                                  
 * 
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported; e.g: source devices.
 * @retval dsERR_OPERATION_FAILED           - The attempted operation has failed
 * 
 * @pre dsHdmiInInit() must be called before calling this API.
 * 
 * @note When a port is selected, activePort should be set to true in  Please refer ::dsHdmiInStatus_t for that port
 *              Also, if thT port has an active connection, it should update isPresented to true as well.
 * 
 * @warning  This API is Not thread safe.
 * 
 */
dsError_t dsHdmiInSelectPort (dsHdmiInPort_t Port, bool audioMix, dsVideoPlaneType_t evideoPlaneType,bool topMost)
{
    // No HDMI-IN support.
    return dsERR_OPERATION_NOT_SUPPORTED;
}

/**
 * @brief Scales the HDMI input video
 *
 * This function scales the HDMI input video. The width and height, based on the x, y coordinates, 
 *      cannot exceed that of the current resolution of the device.
 *      e.g.  x(in pixels)+width cannot be greater then the width of the resolution.
 *      The current resolution will return by  Please refer ::dsGetResolution()
 *
 * @param[in] x         - x coordinate for the video. Min of 0. Max is based on the current resolution
 * @param[in] y         - y coordinate for the video. Min of 0. Max is based on the current resolution
 * @param[in] width     - width of the video. Width in pixels.. Min of 0. Max is based on the current resolution
 * @param[in] height    - height of the video. Height in pixels.. Min of 0. Max is based on the current resolution
 *
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid. 
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported; e.g: source devices
 * @retval dsERR_OPERATION_FAILED           - The attempted operation has failed
 * 
 * @pre dsHdmiInInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 */
dsError_t dsHdmiInScaleVideo (int32_t x, int32_t y, int32_t width, int32_t height)
{
    // No HDMI-IN support.
    return dsERR_OPERATION_NOT_SUPPORTED;
}

/**
 * @brief Updates the video zoom on the active HDMI input using the provided zoom mode
 * 
 * This function updates the video zoom on the active HDMI input using the provided zoom mode.
 *
 * @param[in] requestedZoomMode     - HDMI input zoom mode.  Please refer ::dsVideoZoom_t
 *                                          dsVideoZoom_t is within vidoeDeviceTypes.h
 * 
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported; e.g: source devices
 * @retval dsERR_OPERATION_FAILED           - The attempted operation has failed
 * 
 * @pre dsHdmiInInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 */
dsError_t dsHdmiInSelectZoomMode (dsVideoZoom_t requestedZoomMode)
{
    // No HDMI-IN support.
    return dsERR_OPERATION_NOT_SUPPORTED;
}

/**
 * @brief Gets the current HDMI input video mode of the active port
 * 
 * This function gets the current HDMI input video mode of the active port
 * 
 * @param[out] resolution              - Current video port resolution.  Please refer ::dsVideoPortResolution_t
 *                                          dsVideoPortResolution_t is currently in the audioVisual combined file.
 * 
 * 
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported; e.g: source devices
 * @retval dsERR_OPERATION_FAILED           - The attempted operation has failed
 * 
 * @pre dsHdmiInInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 */
dsError_t dsHdmiInGetCurrentVideoMode (dsVideoPortResolution_t *resolution)
{
    if (NULL == resolution)
        return dsERR_INVALID_PARAM;
    // No HDMI-IN support.
    return dsERR_OPERATION_NOT_SUPPORTED;
}

/**
 * @brief Notifies applications when the HDMI input port connection status changes
 *
 * @param[in] Port              - Port id where connection status is changed.  Please refer ::dsHdmiInPort_t
 * @param[in] isPortConnected   - Flag to control the port connection status. 
 *                                  ( @a true to enable, @a false to disable)
 * 
 * @pre dsHdmiInRegisterConnectCB() must be called before this API
 * 
 * @note This should update isPortConnected in ::dsHdmiInStatus_t when this callback is triggered.
 *          If this port is currently active, and presents video after being connected, isPresented should also be updated
 */
typedef void (*dsHdmiInConnectCB_t)(dsHdmiInPort_t Port, bool isPortConnected)
{
    // No HDMI-IN support.
    // Since this is a callback; add a log to see if this is getting invoked.
    perror("No HDMI-IN support; callbacks should not be invoked.");
}

/**
 * @brief Notifies applications when the HDMI input port signal status changes
 * 
 * @param[in] port      - Port id where signal status is changed. Please refer ::dsHdmiInPort_t
 * @param[in] sigStatus - Current signal status of the port.  Please refer ::dsHdmiInSignalStatus_t
 * 
 * @pre dsHdmiInRegisterSignalChangeCB() must be called before this API
 *
 */
typedef void (*dsHdmiInSignalChangeCB_t)(dsHdmiInPort_t port, dsHdmiInSignalStatus_t sigStatus)
{
    // No HDMI-IN support.
    // Since this is a callback; add a log to see if this is getting invoked.
    perror("No HDMI-IN support; callbacks should not be invoked.");
}

/**
 * @brief Notifies applications when the HDMI input status changes on any port.
 *
 * HAL Implementation must call this method to deliver HDMI input status
 * to the Caller whenever the HDMI input status changes.
 * 
 * @param[in] inputStatus   - Present hdmi input status.  Please refer ::dsHdmiInStatus_t
 * 
 * @pre dsHdmiInRegisterStatusChangeCB() must be called before this API
 * 
 * @note This callback should be triggered whenever dsHdmiInStatus_t is updated.Please refer :: dsHdmiInSelectPort, ::dsHdmiInConnectCB_t()
 *
 */
typedef void (*dsHdmiInStatusChangeCB_t)(dsHdmiInStatus_t inputStatus)
{
    // No HDMI-IN support.
    // Since this is a callback; add a log to see if this is getting invoked.
    perror("No HDMI-IN support; callbacks should not be invoked.");
}

/**
 * @brief Notifies applications when the HDMI input port video mode changes
 *
 * HAL Implementation must call this method to deliver updated HDMI input port video mode info
 * to the Caller
 *
 * @param[in] port              - Port in which video mode updated. Please refer ::dsHdmiInPort_t
 * @param[in] videoResolution   - current video resolution of the port.  Please refer ::dsVideoPortResolution_t
 *                                  dsVideoPortResolution_t is currently in the audioVisual combined file.
 * 
 * @pre dsHdmiInRegisterVideoModeUpdateCB() must be called before this API
 *
 */
typedef void (*dsHdmiInVideoModeUpdateCB_t)(dsHdmiInPort_t port, dsVideoPortResolution_t videoResolution)
{
    // No HDMI-IN support.
    // Since this is a callback; add a log to see if this is getting invoked.
    perror("No HDMI-IN support; callbacks should not be invoked.");
}

/**
 * @brief Notifies applications when the HDMI input ALLM mode changes
 *
 * @param[in] port      - HDMI input port number in which ALLM Mode changed.  Please refer ::dsHdmiInPort_t
 * @param[in] allm_mode - Flag to hold the current ALLM mode of the port.
 *                              ( @a true to enable, @a false to disable)
 * 
 * @pre dsHdmiInRegisterAllmChangeCB() must be called before this API
 *
 */
typedef void (*dsHdmiInAllmChangeCB_t)(dsHdmiInPort_t port, bool allm_mode)
{
    // No HDMI-IN support.
    // Since this is a callback; add a log to see if this is getting invoked.
    perror("No HDMI-IN support; callbacks should not be invoked.");
}

/**
 * @brief Notifies applications of HDMI Input AV Latency
 *
 * HAL Implementation should call this method to deliver HDMI Input AV Latency
 * to the application.
 *
 * @param[in] audio_latency - Audio latency value. Max value 500ms. Min value 0.
 * @param[in] video_latency - Video latency value. Max value 500ms. Min value 0.
 *
 * @pre dsHdmiInRegisterAVLatencyChangeCB() must be called before this API
 */
typedef void (*dsAVLatencyChangeCB_t)(int audio_latency, int video_latency)
{
    // No HDMI-IN support.
    // Since this is a callback; add a log to see if this is getting invoked.
    perror("No HDMI-IN support; callbacks should not be invoked.");
}

/**
 * @brief Notifies applications of HDMI Input Content Type change
 *
 * HAL Implementation should call this method to deliver HDMI Input Content Type change 
 * to the application
 *
 * @param port			    - HDMI Input port.  Please refer ::dsHdmiInPort_t
 * @param avi_content_type	- HDMI port AVI Content Type Info.  Please refer ::dsAviContentType_t
 *
 * @pre dsHdmiInRegisterAviContentTypeChangeCB() must be called before this API
 */
typedef void (*dsHdmiInAviContentTypeChangeCB_t)(dsHdmiInPort_t port, dsAviContentType_t avi_content_type)
{
    // No HDMI-IN support.
    // Since this is a callback; add a log to see if this is getting invoked.
    perror("No HDMI-IN support; callbacks should not be invoked.");
}

/**
 * @brief Registers a callback for the HDMI input hot plug event notification
 * 
 * This function registers a callback for the HDMI input hot plug event notification from the HAL side.
 *
 * @param[in] CBFunc    - HDMI input hot plug callback function.  Please refer ::dsHdmiInConnectCB_t
 * 
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported; e.g: source devices
 * 
 * @pre dsHdmiInInit() must be called before calling this API
 * @see dsHdmiInConnectCB_t
 * 
 * @warning  This API is Not thread safe.
 * 
 */
dsError_t dsHdmiInRegisterConnectCB (dsHdmiInConnectCB_t CBFunc)
{
    // No HDMI-IN support.
    // Since this is a callback; add a log to see if this is getting invoked.
    perror("No HDMI-IN support; callbacks should not be registered.");
    return dsERR_OPERATION_NOT_SUPPORTED;
}

/**
 * @brief Registers a callback for the HDMI input Signal Change event
 * 
 * This function registers a callback for the HDMI input Signal Change event.
 *
 * @param[in] CBFunc    - HDMI input Signal change callback function.  Please refer ::dsHdmiInSignalChangeCB_t
 * 
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported; e.g: source devices
 * 
 * @pre dsHdmiInInit() must be called before calling this API
 * @see dsHdmiInSignalChangeCB_t
 * 
 * @warning  This API is Not thread safe.
 * 
 */
dsError_t dsHdmiInRegisterSignalChangeCB (dsHdmiInSignalChangeCB_t CBFunc)
{
    // No HDMI-IN support.
    // Since this is a callback; add a log to see if this is getting invoked.
    perror("No HDMI-IN support; callbacks should not be registered.");
    return dsERR_OPERATION_NOT_SUPPORTED;
}

/**
 * @brief Registers a callback for the HDMI input Status Change event
 * 
 * This function registers a callback for the HDMI input Status Change event.
 *
 * @param[in] CBFunc    - HDMI input Status change callback function.  Please refer ::dsHdmiInStatusChangeCB_t
 * 
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported; e.g: source devices
 * 
 * @pre dsHdmiInInit() must be called before calling this API
 * @see dsHdmiInStatusChangeCB_t
 * 
 * @warning  This API is Not thread safe.
 * 
 */
dsError_t dsHdmiInRegisterStatusChangeCB (dsHdmiInStatusChangeCB_t CBFunc)
{
    // No HDMI-IN support.
    // Since this is a callback; add a log to see if this is getting invoked.
    perror("No HDMI-IN support; callbacks should not be registered.");
    return dsERR_OPERATION_NOT_SUPPORTED;
}

/**
 * @brief Registers a callback for the HDMI input video mode Change event
 * 
 * This function registers a callback for the HDMI input video mode Change event. 
 *       The mode change is triggered whenever the video resolution changes.
 *
 * @param[in] CBFunc    - HDMI input video mode change callback function. 
 *                              Please refer ::dsHdmiInVideoModeUpdateCB_t
 * 
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported; e.g: source devices
 * 
 * @pre dsHdmiInInit() must be called before calling this API
 * @see dsHdmiInVideoModeUpdateCB_t
 * 
 * @warning  This API is Not thread safe.
 * 
 */
dsError_t dsHdmiInRegisterVideoModeUpdateCB(dsHdmiInVideoModeUpdateCB_t CBFunc)
{
    // No HDMI-IN support.
    // Since this is a callback; add a log to see if this is getting invoked.
    perror("No HDMI-IN support; callbacks should not be registered.");
    return dsERR_OPERATION_NOT_SUPPORTED;
}

/**
 * @brief Registers a callback for the HDMI input ALLM Mode Change event
 * 
 * This function registers a callback for the HDMI input ALLM Mode Change event.
 *
 * @param[in] CBFunc    - HDMI input ALLM Mode change callback function. 
 *                               Please refer ::dsHdmiInAllmChangeCB_t
 * 
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported; e.g: source devices, or ALLM not supported
 * 
 * @pre dsHdmiInInit() must be called before calling this API
 * @see dsHdmiInAllmChangeCB_t
 * 
 * @warning  This API is Not thread safe.
 * 
 */
dsError_t dsHdmiInRegisterAllmChangeCB (dsHdmiInAllmChangeCB_t CBFunc)
{
    // No HDMI-IN support.
    // Since this is a callback; add a log to see if this is getting invoked.
    perror("No HDMI-IN support; callbacks should not be registered.");
    return dsERR_OPERATION_NOT_SUPPORTED;
}

/**
 * @brief Registers the HDMI In Latency Change event
 *
 * This function registers for the AV Latency Change event.
 *
 * @param[in] CBFunc    - HDMI input AV Latency change callback function. 
 *                              Please refer ::dsAVLatencyChangeCB_t
 * 
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported; e.g: AV Latency not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsHdmiInInit() must be called before calling this API
 * @see dsAVLatencyChangeCB_t
 *
 * @warning  This API is Not thread safe.
 * 
 */
dsError_t dsHdmiInRegisterAVLatencyChangeCB (dsAVLatencyChangeCB_t CBFunc)
{
    // No HDMI-IN support.
    // Since this is a callback; add a log to see if this is getting invoked.
    perror("No HDMI-IN support; callbacks should not be registered.");
    return dsERR_OPERATION_NOT_SUPPORTED;
}

/**
 * @brief Registers the HDMI Input Content type Change event
 *
 * This function registers for the HDMI Input content type change event.
 *
 * @param[in] CBFunc    - HDMI input Avi Content Mode change callback function. 
 *                               Please refer ::dsHdmiInAviContentTypeChangeCB_t
 * 
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported; e.g: AVI content type not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 *
 * @pre dsHdmiInInit() must be called before calling this API
 * @see dsHdmiInAviContentTypeChangeCB_t
 * 
 * @warning  This API is Not thread safe.
 * 
 */
dsError_t dsHdmiInRegisterAviContentTypeChangeCB (dsHdmiInAviContentTypeChangeCB_t CBFunc)
{
    // No HDMI-IN support.
    // Since this is a callback; add a log to see if this is getting invoked.
    perror("No HDMI-IN support; callbacks should not be registered.");
    return dsERR_OPERATION_NOT_SUPPORTED;
}

/**
 * @brief Checks if the given port is an HDMI ARC port or not
 * 
 * This function checks if the given port is an HDMI ARC port or not
 *
 * @param[in] iPort     - HDMI Arc port. Max value is device specific. Min value of 0
 * @param[out] isArcPort - Flag to hold the HDMI Arc port status 
 *                              ( @a true to enable, @a false to disable)
 *
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported; e.g: source devices
 * @retval dsERR_OPERATION_FAILED           - The attempted operation has failed
 * 
 * @pre dsHdmiInInit() must be called before calling this API
 * 
 * @warning  This API is Not thread safe.
 * 
 */
dsError_t dsIsHdmiARCPort (dsHdmiInPort_t iPort, bool *isArcPort)
{
    if (NULL == isArcPort)
        return dsERR_INVALID_PARAM;
    // No HDMI-IN support.
    return dsERR_OPERATION_NOT_SUPPORTED;
}

/**
 * @brief Gets the EDID bytes info corresponds to the given input port
 * 
 * This function gets the EDID bytes info corresponds to the given input port.
 *
 * @param[in] iHdmiPort     - HDMI input port.  Please refer ::dsHdmiInPort_t
 * @param[out] edid         - EDID data for which info is required
 * @param[out] length       - length of the EDID data. Min value of 0. Max length 256.
 *
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported; e.g: source devices
 * @retval dsERR_OPERATION_FAILED           - The attempted operation has failed
 * 
 * @pre dsHdmiInInit() must be called before calling this API
 * 
 * @warning  This API is Not thread safe.
 * 
 */
dsError_t dsGetEDIDBytesInfo (dsHdmiInPort_t iHdmiPort, unsigned char *edid, int *length)
{
    if ((NULL == edid) || (NULL == length))
        return dsERR_INVALID_PARAM;
    // No HDMI-IN support.
    return dsERR_OPERATION_NOT_SUPPORTED;
}

/**
 * @brief Gets the HDMI SPD info
 * 
 * This function gets the HDMI SPD info.
 *
 * @param[in] iHdmiPort     - HDMI input port. Please refer ::dsHdmiInPort_t
 * @param[out] data         - HDMI SPD info data
 *                              Should not exceed sizeof(dsSpd_infoframe_st).  Please refer ::dsSpd_infoframe_st
 *
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported; e.g: source devices
 * @retval dsERR_OPERATION_FAILED           - The attempted operation has failed
 * 
 * @pre dsHdmiInInit() must be called before calling this API
 * 
 * @warning  This API is Not thread safe.
 * 
 */
dsError_t dsGetHDMISPDInfo (dsHdmiInPort_t iHdmiPort, unsigned char *data)
{
    if (NULL == data)
        return dsERR_INVALID_PARAM;
    // No HDMI-IN support.
    return dsERR_OPERATION_NOT_SUPPORTED;
}

/**
 * @brief Sets the EDID version to be used for a given port id
 * 
 * This function sets the EDID version to be used for a given port id
 *
 * @param[in] iHdmiPort     - HDMI input port.  Please refer ::dsHdmiInPort_t
 * @param[in] iEdidVersion  - input EDID version number to set.  Please refer ::tv_hdmi_edid_version_t
 *
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported; e.g: source devices
 * @retval dsERR_OPERATION_FAILED           - The attempted operation has failed
 * 
 * @pre dsHdmiInInit() must be called before calling this API
 * 
 * @warning  This API is Not thread safe
 * 
 * @see dsGetEdidVersion()
 * 
 */
dsError_t dsSetEdidVersion (dsHdmiInPort_t iHdmiPort, tv_hdmi_edid_version_t iEdidVersion)
{
    // No HDMI-IN support.
    return dsERR_OPERATION_NOT_SUPPORTED;
}

/**
 * @brief Gets the EDID version currently being used for the given port id
 * 
 * This function gets the EDID version currently being used for the given port id
 *
 * @param[in] iHdmiPort     - HDMI input port.  Please refer ::dsHdmiInPort_t
 * @param[out] iEdidVersion - input EDID version number.  Please refer ::tv_hdmi_edid_version_t
 *
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported; e.g: source devices
 * @retval dsERR_OPERATION_FAILED           - The attempted operation has failed
 * 
 * @pre dsHdmiInInit() must be called before calling this API
 * 
 * @warning  This API is Not thread safe
 * 
 * @see dsSetEdidVersion()
 * 
 */
dsError_t dsGetEdidVersion (dsHdmiInPort_t iHdmiPort, tv_hdmi_edid_version_t *iEdidVersion)
{
    if (NULL == iEdidVersion)
        return dsERR_INVALID_PARAM;
    // No HDMI-IN support.
    return dsERR_OPERATION_NOT_SUPPORTED;
}

/**
 * @brief Checks whether ALLM status is enabled or disabled for the specific HDMI input port
 * 
 * This function checks whether ALLM status is enabled or disabled for the specific HDMI input port
 *
 * @param[in] iHdmiPort     - HDMI input port.  Please refer ::dsHdmiInPort_t
 * @param[out] allmStatus   - Flag to control the allm status
 *                              ( @a true to enable, @a false to disable)
 *
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported; e.g: source devices
 * @retval dsERR_OPERATION_FAILED           - The attempted operation has failed
 * 
 * @pre dsHdmiInInit() must be called before calling this API
 * 
 * @warning  This API is Not thread safe
 * 
 */
dsError_t dsGetAllmStatus (dsHdmiInPort_t iHdmiPort, bool *allmStatus)
{
    if (NULL == allmStatus)
        return dsERR_INVALID_PARAM;
    // No HDMI-IN support.
    return dsERR_OPERATION_NOT_SUPPORTED;
}

/**
 * @brief Gets all the supported game features list information
 * 
 * This function gets all the supported game features list information.
 *
 * @param[out] features         - List of all supported game features. 
 *                                       Please refer ::dsSupportedGameFeatureList_t
 *
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported; e.g: source devices
 * @retval dsERR_OPERATION_FAILED           - The attempted operation has failed
 * 
 * @pre dsHdmiInInit() must be called before calling this API
 * 
 * @warning  This API is Not thread safe
 * 
 */
dsError_t dsGetSupportedGameFeaturesList (dsSupportedGameFeatureList_t* features)
{
    if (NULL == features)
        return dsERR_INVALID_PARAM;
    // No HDMI-IN support.
    return dsERR_OPERATION_NOT_SUPPORTED;
}

/**
 * @brief Gets the current AV latency
 * 
 * This function gets the current AV latency.
 *
 * @param[out] audio_latency    - Audio latency value. Max value 500ms. Min value 0
 * @param[out] video_latency    - Video latency value. Max value 500ms. Min value 0
 *
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported; e.g: source devices
 * @retval dsERR_OPERATION_FAILED           - The attempted operation has failed
 * 
 * @pre dsHdmiInInit() must be called before calling this API
 * 
 * @warning  This API is Not thread safe
 * 
 */
dsError_t dsGetAVLatency (int *audio_latency, int *video_latency)
{
    if ((NULL == audio_latency) || (NULL == video_latency))
        return dsERR_INVALID_PARAM;
    // No HDMI-IN support.
    return dsERR_OPERATION_NOT_SUPPORTED;
}


/**
 * @brief Sets the EDID ALLM support
 * 
 * This function sets the EDID ALLM support
 *
 * @param[in] iHdmiPort      - HDMI input port.  Please refer ::dsHdmiInPort_t
 * @param[in] allmSupport    - Allm support. False for disabled, True for enabled
 *
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported; e.g: source devices
 * @retval dsERR_OPERATION_FAILED           - The attempted operation has failed
 * 
 * @pre dsHdmiInInit() must be called before calling this API
 * 
 * @warning  This API is Not thread safe
 * 
 */
dsError_t dsSetEdid2AllmSupport (dsHdmiInPort_t iHdmiPort, bool allmSupport)
{
    // No HDMI-IN support.
    return dsERR_OPERATION_NOT_SUPPORTED;
}

/**
 * @brief Sets the EDID ALLM support
 * 
 * This function sets the EDID ALLM support
 *
 * @param[in] iHdmiPort    - HDMI input port.  Please refer ::dsHdmiInPort_t
 * @param[out] allmSupport - Allm support. False for disabled, True for enabled
 *
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported; e.g: source devices
 * @retval dsERR_OPERATION_FAILED           - The attempted operation has failed
 * 
 * @pre dsHdmiInInit() must be called before calling this API
 * 
 * @warning  This API is Not thread safe
 * 
 */
dsError_t dsGetEdid2AllmSupport (dsHdmiInPort_t iHdmiPort, bool *allmSupport)
{
    if (NULL == allmSupport)
        return dsERR_INVALID_PARAM;
    // No HDMI-IN support.
    return dsERR_OPERATION_NOT_SUPPORTED;
}


#ifdef __cplusplus
}
#endif

