/*
* Copyright (c) 2014 Microsoft Open Technologies, Inc. 
*   
*    Licensed under the Apache License, Version 2.0 (the "License"); you may 
*    not use this file except in compliance with the License. You may obtain 
*    a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
*
*    THIS CODE IS PROVIDED ON AN  *AS IS* BASIS, WITHOUT WARRANTIES OR 
*    CONDITIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT 
*    LIMITATION ANY IMPLIED WARRANTIES OR CONDITIONS OF TITLE, FITNESS 
*    FOR A PARTICULAR PURPOSE, MERCHANTABLITY OR NON-INFRINGEMENT.
*
*    See the Apache Version 2.0 License for specific language governing 
*    permissions and limitations under the License. 
*
*    Microsoft would like to thank the following companies for their review and
*    assistance with these files: Intel Corporation, Mellanox Technologies Ltd,
*    Dell Products, L.P., Facebook, Inc
*   
* Module Name:
*
*    saiport.h
*
* Abstract:
*
*    This module defines SAI Port API
*
*/

#if !defined (__SAIPORT_H_)
#define __SAIPORT_H_

#include <saitypes.h>

#define PORT_COUNTER_SET_DEFAULT    0


/*
*  Attribute data for SAI_PORT_ATTR_TYPE
*/
typedef enum _sai_port_type_t
{
    /* Undefined */
    SAI_PORT_TYPE_UNDEFINED,

    /* Actual port. N.B. Different from the physical port. */
    SAI_PORT_TYPE_LOGICAL,

    /* CPU Port */
    SAI_PORT_TYPE_CPU,

    /* Link-Aggregation Port */
    SAI_PORT_TYPE_LAG,

} sai_port_type_t;

/*
*  Attribute data for SAI_PORT_ATTR_OPER_STATUS 
*/
typedef enum _sai_port_oper_status_t
{
    /* Unknown */
    SAI_PORT_OPER_STATUS_UNKNOWN,

    /* Up */
    SAI_PORT_OPER_STATUS_UP,

    /* Down */
    SAI_PORT_OPER_STATUS_DOWN,

    /* Test Running */
    SAI_PORT_OPER_STATUS_TESTING,

    /* Not Present */
    SAI_PORT_OPER_STATUS_NOT_PRESENT

} sai_port_oper_status_t;


/*
*  Attribute data for SAI_PORT_STP_MODE
*/
typedef enum _sai_port_stp_mode_t 
{
    /* Spanning-Tree Disabled */
    SAI_PORT_STP_MODE_DISABLED,

    /* Spanning-Tree */
    SAI_PORT_STP_MODE_STP,

    /* Rapid Spanning-Tree */
    SAI_PORT_STP_MODE_RSTP,

} sai_port_stp_mode_t;


/*
*  Attribute data for SAI_PORT_STP_STATE
*/
typedef enum _sai_port_stp_port_state_t 
{
    /* Port is Disabled  */
    SAI_PORT_STP_STATE_DISABLED,

    /* Port is Listening */
    SAI_PORT_STP_STATE_LISTENING,

    /* Port is Learning */
    SAI_PORT_STP_STATE_LEARNING,

    /* Port is Forwarding */
    SAI_PORT_STP_STATE_FORWARDING,

    /* Port is Blocking */
    SAI_PORT_STP_STATE_BLOCKING,

    /* Port is Discarding */
    SAI_PORT_STP_STATE_DISCARDING,

} sai_port_stp_port_state_t;


/*
*  Attribute Id in sai_set_port_attribute() and 
*  sai_get_port_attribute() calls
*/
typedef enum _sai_port_attr_t
{
    /* READ-ONLY */

    /* Admin Mode [sai_port_type_t] */
    SAI_PORT_ATTR_TYPE,

    /* Speed in Mbps [uint_t] */
    SAI_PORT_ATTR_SPEED,

    /* Operational Status [sai_port_oper_status_t] */
    SAI_PORT_ATTR_OPER_STATUS,


    /* READ-WRITE */

    /* Admin Mode [bool] */
    SAI_PORT_ATTR_ADMIN_STATE,

    /* Default VLAN [uint32_t] 
    *   Untagged ingress frames are tagged with default VLAN 
    */
    SAI_PORT_ATTR_DEFAULT_VLAN,

    /* Default VLAN Priority [int] */
    SAI_PORT_ATTR_DEFAULT_VLAN_PRIORITY,

    /* Ingress Filtering (Drop Frames with Unknown VLANs) [bool] */
    SAI_PORT_ATTR_INGRESS_FILTERING,

    /* Dropping of untagged frames on ingress [bool] */
    SAI_PORT_ATTR_DROP_UNTAGGED, 

    /* Dropping of tagged frames on ingress [bool] */
    SAI_PORT_ATTR_DROP_TAGGED, 

    /* Internal loopback control [bool] */
    SAI_PORT_ATTR_INTERNAL_LOOPBACK,

    /* FDB Learning [bool] */
    SAI_PORT_ATTR_FDB_LEARNING,

    /* Stp mode [sai_port_stp_mode_t] */
    SAI_PORT_ATTR_STP_MODE,

    /* Stp mode [sai_port_stp_state_t] */
    SAI_PORT_ATTR_STP_STATE,

    /* Update DSCP of outgoing packets [bool] */
    SAI_PORT_ATTR_UPDATE_DSCP,

    /* MTU [uint32_t] */
    SAI_PORT_ATTR_MTU,

    /* Sflow control */
    SAI_PORT_ATTR_SFLOW,

    /* [bool] */
    SAI_PORT_ATTR_FLOOD_STORM_CONTROL,

    /* [bool] */
    SAI_PORT_ATTR_BOADCAST_STORM_CONTROL,

    /* [bool] */
    SAI_PORT_ATTR_MULTICAST_STORM_CONTROL,

    /* [bool] */
    SAI_PORT_ATTR_GLOBOL_FLOW_CONTROL,

    /* Maximum number of learned MAC addresses [uint32_t] */
    SAI_PORT_ATTR_MAX_LEARNED_ADDRESSES,

    /* -- */

    /* Custom range base value */
    SAI_PORT_ATTR_CUSTOM_RANGE_BASE  = 0x10000000

} sai_port_attr_t;

/*
* Port mapping (sai_port mapped to physical port:lane_bitmap table 
* passed to the adapter via sai_initialize_switch()
*/
typedef struct sai_port_mapping {
    sai_port_id_t         local_port;
    sai_port_phy_id_t     phy_port;
    sai_port_lane_bmap_t  lane_bmap;
} sai_port_mapping_t;

/*
*  Port counter IDs in sai_get_port_stat_counters() call
*/
typedef enum _sai_port_stat_counter_t
{
    SAI_PORT_STAT_IF_IN_OCTETS,
    SAI_PORT_STAT_IF_IN_UCAST_PKTS,
    SAI_PORT_STAT_IF_IN_NON_UCAST_PKTS,
    SAI_PORT_STAT_IF_IN_DISCARDS,
    SAI_PORT_STAT_IF_IN_ERRORS,
    SAI_PORT_STAT_IF_IN_UNKNOWN_PROTOS,
    SAI_PORT_STAT_IF_IN_BROADCAST_PKTS,
    SAI_PORT_STAT_IF_IN_MULTICAST_PKTS,
    SAI_PORT_STAT_IF_IN_VLAN_DISCARDS,
    SAI_PORT_STAT_IF_OUT_OCTETS,
    SAI_PORT_STAT_IF_OUT_UCAST_PKTS,
    SAI_PORT_STAT_IF_OUT_NON_UCAST_PKTS,
    SAI_PORT_STAT_IF_OUT_DISCARDS,
    SAI_PORT_STAT_IF_OUT_ERRORS,
    SAI_PORT_STAT_IF_OUT_QLEN,
    SAI_PORT_STAT_IF_OUT_BROADCAST_PKTS,
    SAI_PORT_STAT_IF_OUT_MULTICAST_PKTS,
    SAI_PORT_STAT_ETHER_STATS_DROP_EVENTS,
    SAI_PORT_STAT_ETHER_STATS_MULTICAST_PKTS,
    SAI_PORT_STAT_ETHER_STATS_BROADCAST_PKTS,
    SAI_PORT_STAT_ETHER_STATS_UNDERSIZE_PKTS,
    SAI_PORT_STAT_ETHER_STATS_FRAGMENTS,
    SAI_PORT_STAT_ETHER_STATS_PKTS_64O_CTETS,
    SAI_PORT_STAT_ETHER_STATS_PKTS_65_TO_127_OCTETS,
    SAI_PORT_STAT_ETHER_STATS_PKTS_128_TO_255_OCTETS,
    SAI_PORT_STAT_ETHER_STATS_PKTS_256_TO_511_OCTETS,
    SAI_PORT_STAT_ETHER_STATS_PKTS_512_TO_1023_OCTETS,
    SAI_PORT_STAT_ETHER_STATS_PKTS_1024_TO_1518_OCTETS,
    SAI_PORT_STAT_ETHER_STATS_OVERSIZE_PKTS,
    SAI_PORT_STAT_ETHER_RX_OVERSIZE_PKTS,
    SAI_PORT_STAT_ETHER_TX_OVERSIZE_PKTS,
    SAI_PORT_STAT_ETHER_STATS_JABBERS,
    SAI_PORT_STAT_ETHER_STATS_OCTETS,
    SAI_PORT_STAT_ETHER_STATS_PKTS,
    SAI_PORT_STAT_ETHER_STATS_COLLISIONS,
    SAI_PORT_STAT_ETHER_STATS_CRC_ALIGN_ERRORS,
    SAI_PORT_STAT_ETHER_STATS_TX_NO_ERRORS,
    SAI_PORT_STAT_ETHER_STATS_RX_NO_ERRORS,
    SAI_PORT_STAT_IP_IN_RECEIVES,
    SAI_PORT_STAT_IP_IN_OCTETS,
    SAI_PORT_STAT_IP_IN_UCAST_PKTS,
    SAI_PORT_STAT_IP_IN_NON_UCAST_PKTS,
    SAI_PORT_STAT_IP_IN_DISCARDS,
    SAI_PORT_STAT_IP_OUT_OCTETS,
    SAI_PORT_STAT_IP_OUT_UCAST_PKTS,
    SAI_PORT_STAT_IP_OUT_NON_UCAST_PKTS,
    SAI_PORT_STAT_IP_OUT_DISCARDS,
    SAI_PORT_STAT_IPV6_IN_RECEIVES,
    SAI_PORT_STAT_IPV6_IN_OCTETS,
    SAI_PORT_STAT_IPV6_IN_UCAST_PKTS,
    SAI_PORT_STAT_IPV6_IN_NON_UCAST_PKTS,
    SAI_PORT_STAT_IPV6_IN_MCAST_PKTS,
    SAI_PORT_STAT_IPV6_IN_DISCARDS,
    SAI_PORT_STAT_IPV6_OUT_OCTETS,
    SAI_PORT_STAT_IPV6_OUT_UCAST_PKTS,
    SAI_PORT_STAT_IPV6_OUT_NON_UCAST_PKTS,
    SAI_PORT_STAT_IPV6_OUT_MCAST_PKTS,
    SAI_PORT_STAT_IPV6_OUT_DISCARDS
} sai_port_stat_counter_t;


/*
* Routine Description:
*   Set port attribute value.
*
* Arguments:
*    [in] port_id - port id
*    [in] attribute - port attribute.
*    [in] value - port attribute value.
*
* Return Values:
*    SAI_STATUS_SUCCESS on success
*    Failure status code on error
*/
typedef sai_status_t (*sai_set_port_attribute_fn)(
    _In_ sai_port_id_t port_id, 
    _In_ sai_port_attr_t attribute,
    _In_ uint64_t value
    );


/*
* Routine Description:
*   Get port attribute value.
*
* Arguments:
*    [in] port_id - port id
*    [in] attribute - port attribute.
*    [out] value - port attribute value.
*
* Return Values:
*    SAI_STATUS_SUCCESS on success
*    Failure status code on error
*/
typedef sai_status_t (*sai_get_port_attribute_fn)(
    _In_ sai_port_id_t port_id,
    _In_ sai_port_attr_t attribute,
    _Out_ uint64_t* value
    );

/*
* Routine Description:
*   Enable/disable statistics counters for port.
*
* Arguments:
*    [in] port_id - port id
*    [in] counter_set_id - specifies the counter set
*    [in] enable - TRUE to enable, FALSE to disable
*
* Return Values:
*    SAI_STATUS_SUCCESS        on success
*    Failure status code on error
*/ 
typedef sai_status_t (*sai_ctl_port_stats_fn)(
    _In_ sai_port_id_t port_id,
    _In_ uint32_t port_counter_set_id,
    _In_ bool enable
    );

/*
* Routine Description:
*   Get port statistics counters.
*
* Arguments:
*    [in] port_id - port id
*    [in] counter_ids - specifies the array of counter ids
*    [in] number_of_counters - number of counters in the array
*    [out] counters - array of resulting counter values.
*
* Return Values:
*    SAI_STATUS_SUCCESS on success
*    Failure status code on error
*/ 
typedef sai_status_t (*sai_get_port_stats_fn)(
    _In_ sai_port_id_t port_id,
    _In_ sai_port_stat_counter_t *counter_ids,
    _In_ uint32_t number_of_counters,
    _Out_ uint64_t* counters
    );

/*
* Routine Description:
*   Port state change notification
*   Passed as a parameter into sai_open_switch()
*
* Arguments:
*   [in] port_id - port id
*   [in] port_state - new port state
*
* Return Values:
*    None
*/
typedef void (*sai_port_state_change_notification_fn)(
    _In_ sai_port_id_t port_id,
    _In_ sai_port_oper_status_t port_state
    );

/*
* Port methods table retrieved with sai_api_query()
*/
typedef struct _sai_port_api_t
{
    sai_set_port_attribute_fn       set_attribute;
    sai_get_port_attribute_fn       get_attribute;
    sai_ctl_port_stats_fn           ctl_stats;
    sai_get_port_stats_fn           get_stats;
} sai_port_api_t;

#endif // __SAIPORT_H_

