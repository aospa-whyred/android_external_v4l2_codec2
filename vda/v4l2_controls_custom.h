// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Note:
// This header file has extracted some new structs and definitions in videodev2.h from ChromeOS
// which is not upstreamed in Linux mainline. This should be removed once they are upstreamed.
// TODO(johnylin): remove this file once it is upstreamed.

#ifndef V4L2_CONTROLS_CUSTOM_H_
#define V4L2_CONTROLS_CUSTOM_H_

#include <linux/v4l2-controls.h>

#define V4L2_CID_MPEG_VIDEO_H264_SPS (V4L2_CID_MPEG_BASE+383)
#define V4L2_CID_MPEG_VIDEO_H264_PPS (V4L2_CID_MPEG_BASE+384)
#define V4L2_CID_MPEG_VIDEO_H264_SCALING_MATRIX (V4L2_CID_MPEG_BASE+385)
#define V4L2_CID_MPEG_VIDEO_H264_SLICE_PARAM (V4L2_CID_MPEG_BASE+386)
#define V4L2_CID_MPEG_VIDEO_H264_DECODE_PARAM (V4L2_CID_MPEG_BASE+387)
#define V4L2_CID_MPEG_VIDEO_H264_SPS_PPS_BEFORE_IDR (V4L2_CID_MPEG_BASE+388)

#define V4L2_CID_MPEG_VIDEO_VP8_FRAME_HDR (V4L2_CID_MPEG_BASE+512)

#define V4L2_CID_MPEG_VIDEO_VP9_FRAME_HDR (V4L2_CID_MPEG_BASE+513)
#define V4L2_CID_MPEG_VIDEO_VP9_DECODE_PARAM (V4L2_CID_MPEG_BASE+514)
#define V4L2_CID_MPEG_VIDEO_VP9_ENTROPY (V4L2_CID_MPEG_BASE+515)

/* Complex controls */

#define V4L2_H264_SPS_CONSTRAINT_SET0_FLAG 0x01
#define V4L2_H264_SPS_CONSTRAINT_SET1_FLAG 0x02
#define V4L2_H264_SPS_CONSTRAINT_SET2_FLAG 0x04
#define V4L2_H264_SPS_CONSTRAINT_SET3_FLAG 0x08
#define V4L2_H264_SPS_CONSTRAINT_SET4_FLAG 0x10
#define V4L2_H264_SPS_CONSTRAINT_SET5_FLAG 0x20

#define V4L2_H264_SPS_FLAG_SEPARATE_COLOUR_PLANE 0x01
#define V4L2_H264_SPS_FLAG_QPPRIME_Y_ZERO_TRANSFORM_BYPASS 0x02
#define V4L2_H264_SPS_FLAG_DELTA_PIC_ORDER_ALWAYS_ZERO 0x04
#define V4L2_H264_SPS_FLAG_GAPS_IN_FRAME_NUM_VALUE_ALLOWED 0x08
#define V4L2_H264_SPS_FLAG_FRAME_MBS_ONLY 0x10
#define V4L2_H264_SPS_FLAG_MB_ADAPTIVE_FRAME_FIELD 0x20
#define V4L2_H264_SPS_FLAG_DIRECT_8X8_INFERENCE 0x40
struct v4l2_ctrl_h264_sps {
  __u8 profile_idc;
  __u8 constraint_set_flags;
  __u8 level_idc;
  __u8 seq_parameter_set_id;
  __u8 chroma_format_idc;
  __u8 bit_depth_luma_minus8;
  __u8 bit_depth_chroma_minus8;
  __u8 log2_max_frame_num_minus4;
  __u8 pic_order_cnt_type;
  __u8 log2_max_pic_order_cnt_lsb_minus4;
  __s32 offset_for_non_ref_pic;
  __s32 offset_for_top_to_bottom_field;
  __u8 num_ref_frames_in_pic_order_cnt_cycle;
  __s32 offset_for_ref_frame[255];
  __u8 max_num_ref_frames;
  __u16 pic_width_in_mbs_minus1;
  __u16 pic_height_in_map_units_minus1;
  __u8 flags;
};

#define V4L2_H264_PPS_FLAG_ENTROPY_CODING_MODE 0x0001
#define V4L2_H264_PPS_FLAG_BOTTOM_FIELD_PIC_ORDER_IN_FRAME_PRESENT 0x0002
#define V4L2_H264_PPS_FLAG_WEIGHTED_PRED 0x0004
#define V4L2_H264_PPS_FLAG_DEBLOCKING_FILTER_CONTROL_PRESENT 0x0008
#define V4L2_H264_PPS_FLAG_CONSTRAINED_INTRA_PRED 0x0010
#define V4L2_H264_PPS_FLAG_REDUNDANT_PIC_CNT_PRESENT 0x0020
#define V4L2_H264_PPS_FLAG_TRANSFORM_8X8_MODE 0x0040
#define V4L2_H264_PPS_FLAG_PIC_SCALING_MATRIX_PRESENT 0x0080
struct v4l2_ctrl_h264_pps {
  __u8 pic_parameter_set_id;
  __u8 seq_parameter_set_id;
  __u8 num_slice_groups_minus1;
  __u8 num_ref_idx_l0_default_active_minus1;
  __u8 num_ref_idx_l1_default_active_minus1;
  __u8 weighted_bipred_idc;
  __s8 pic_init_qp_minus26;
  __s8 pic_init_qs_minus26;
  __s8 chroma_qp_index_offset;
  __s8 second_chroma_qp_index_offset;
  __u8 flags;
};

struct v4l2_ctrl_h264_scaling_matrix {
  __u8 scaling_list_4x4[6][16];
  __u8 scaling_list_8x8[6][64];
};

struct v4l2_h264_weight_factors {
  __s8 luma_weight[32];
  __s8 luma_offset[32];
  __s8 chroma_weight[32][2];
  __s8 chroma_offset[32][2];
};

struct v4l2_h264_pred_weight_table {
  __u8 luma_log2_weight_denom;
  __u8 chroma_log2_weight_denom;
  struct v4l2_h264_weight_factors weight_factors[2];
};

#define V4L2_SLICE_FLAG_FIELD_PIC 0x01
#define V4L2_SLICE_FLAG_BOTTOM_FIELD 0x02
#define V4L2_SLICE_FLAG_DIRECT_SPATIAL_MV_PRED 0x04
#define V4L2_SLICE_FLAG_SP_FOR_SWITCH 0x08
struct v4l2_ctrl_h264_slice_param {
  /* Size in bytes, including header */
  __u32 size;
  /* Offset in bits to slice_data() from the beginning of this slice. */
  __u32 header_bit_size;

  __u16 first_mb_in_slice;
  __u8 slice_type;
  __u8 pic_parameter_set_id;
  __u8 colour_plane_id;
  __u16 frame_num;
  __u16 idr_pic_id;
  __u16 pic_order_cnt_lsb;
  __s32 delta_pic_order_cnt_bottom;
  __s32 delta_pic_order_cnt0;
  __s32 delta_pic_order_cnt1;
  __u8 redundant_pic_cnt;

  struct v4l2_h264_pred_weight_table pred_weight_table;
  /* Size in bits of dec_ref_pic_marking() syntax element. */
  __u32 dec_ref_pic_marking_bit_size;
  /* Size in bits of pic order count syntax. */
  __u32 pic_order_cnt_bit_size;

  __u8 cabac_init_idc;
  __s8 slice_qp_delta;
  __s8 slice_qs_delta;
  __u8 disable_deblocking_filter_idc;
  __s8 slice_alpha_c0_offset_div2;
  __s8 slice_beta_offset_div2;
  __u32 slice_group_change_cycle;

  __u8 num_ref_idx_l0_active_minus1;
  __u8 num_ref_idx_l1_active_minus1;
  /*  Entries on each list are indices
   *  into v4l2_ctrl_h264_decode_param.dpb[]. */
  __u8 ref_pic_list0[32];
  __u8 ref_pic_list1[32];

  __u8 flags;
};

/* If not set, this entry is unused for reference. */
#define V4L2_H264_DPB_ENTRY_FLAG_ACTIVE 0x01
#define V4L2_H264_DPB_ENTRY_FLAG_LONG_TERM 0x02
struct v4l2_h264_dpb_entry {
  __u32 buf_index; /* v4l2_buffer index */
  __u16 frame_num;
  __u16 pic_num;
  /* Note that field is indicated by v4l2_buffer.field */
  __s32 top_field_order_cnt;
  __s32 bottom_field_order_cnt;
  __u8 flags; /* V4L2_H264_DPB_ENTRY_FLAG_* */
};

struct v4l2_ctrl_h264_decode_param {
  __u32 num_slices;
  __u8 idr_pic_flag;
  __u8 nal_ref_idc;
  __s32 top_field_order_cnt;
  __s32 bottom_field_order_cnt;
  __u8 ref_pic_list_p0[32];
  __u8 ref_pic_list_b0[32];
  __u8 ref_pic_list_b1[32];
  struct v4l2_h264_dpb_entry dpb[16];
};

#define V4L2_VP8_SEGMNT_HDR_FLAG_ENABLED 0x01
#define V4L2_VP8_SEGMNT_HDR_FLAG_UPDATE_MAP 0x02
#define V4L2_VP8_SEGMNT_HDR_FLAG_UPDATE_FEATURE_DATA 0x04
struct v4l2_vp8_sgmnt_hdr {
  __u8 segment_feature_mode;

  __s8 quant_update[4];
  __s8 lf_update[4];
  __u8 segment_probs[3];

  __u8 flags;
};

#define V4L2_VP8_LF_HDR_ADJ_ENABLE 0x01
#define V4L2_VP8_LF_HDR_DELTA_UPDATE 0x02
struct v4l2_vp8_loopfilter_hdr {
  __u8 type;
  __u8 level;
  __u8 sharpness_level;
  __s8 ref_frm_delta_magnitude[4];
  __s8 mb_mode_delta_magnitude[4];

  __u8 flags;
};

struct v4l2_vp8_quantization_hdr {
  __u8 y_ac_qi;
  __s8 y_dc_delta;
  __s8 y2_dc_delta;
  __s8 y2_ac_delta;
  __s8 uv_dc_delta;
  __s8 uv_ac_delta;
  __u16 dequant_factors[4][3][2];
};

struct v4l2_vp8_entropy_hdr {
  __u8 coeff_probs[4][8][3][11];
  __u8 y_mode_probs[4];
  __u8 uv_mode_probs[3];
  __u8 mv_probs[2][19];
};

#define V4L2_VP8_FRAME_HDR_FLAG_EXPERIMENTAL 0x01
#define V4L2_VP8_FRAME_HDR_FLAG_SHOW_FRAME 0x02
#define V4L2_VP8_FRAME_HDR_FLAG_MB_NO_SKIP_COEFF 0x04
struct v4l2_ctrl_vp8_frame_hdr {
  /* 0: keyframe, 1: not a keyframe */
  __u8 key_frame;
  __u8 version;

  /* Populated also if not a key frame */
  __u16 width;
  __u8 horizontal_scale;
  __u16 height;
  __u8 vertical_scale;

  struct v4l2_vp8_sgmnt_hdr sgmnt_hdr;
  struct v4l2_vp8_loopfilter_hdr lf_hdr;
  struct v4l2_vp8_quantization_hdr quant_hdr;
  struct v4l2_vp8_entropy_hdr entropy_hdr;

  __u8 sign_bias_golden;
  __u8 sign_bias_alternate;

  __u8 prob_skip_false;
  __u8 prob_intra;
  __u8 prob_last;
  __u8 prob_gf;

  __u32 first_part_size;
  __u32 first_part_offset;
  /*
   * Offset in bits of MB data in first partition,
   * i.e. bit offset starting from first_part_offset.
   */
  __u32 macroblock_bit_offset;

  __u8 num_dct_parts;
  __u32 dct_part_sizes[8];

  __u8 bool_dec_range;
  __u8 bool_dec_value;
  __u8 bool_dec_count;

  /* v4l2_buffer indices of reference frames */
  __u32 last_frame;
  __u32 golden_frame;
  __u32 alt_frame;

  __u8 flags;
};

#define V4L2_VP9_SGMNT_PARAM_FLAG_ENABLED 0x01
#define V4L2_VP9_SGMNT_PARAM_FLAG_UPDATE_MAP 0x02
#define V4L2_VP9_SGMNT_PARAM_FLAG_TEMPORAL_UPDATE 0x04
#define V4L2_VP9_SGMNT_PARAM_FLAG_UPDATE_DATA 0x08
#define V4L2_VP9_SGMNT_PARAM_FLAG_ABS_OR_DELTA_UPDATE 0x10
struct v4l2_vp9_segmentation_params {
  __u8 tree_probs[7];
  __u8 pred_probs[3];
  __u8 feature_enabled[8][4];
  __s16 feature_data[8][4];

  __u8 flags;
};

#define V4L2_VP9_LOOP_FLTR_FLAG_DELTA_ENABLED 0x01
#define V4L2_VP9_LOOP_FLTR_FLAG_DELTA_UPDATE 0x02
struct v4l2_vp9_loop_filter_params {
  __u8 level;
  __u8 sharpness;
  __s8 deltas[4];
  __s8 mode_deltas[2];
  __u8 lvl_lookup[8][4][2];

  __u8 flags;
};

#define V4L2_VP9_QUANT_PARAMS_FLAG_LOSSLESS 0x01
struct v4l2_vp9_quantization_params {
  __u8 base_q_idx;
  __s8 delta_q_y_dc;
  __s8 delta_q_uv_dc;
  __s8 delta_q_uv_ac;

  __u8 flags;
};

#define V4L2_VP9_FRAME_HDR_FLAG_SHOW_FRAME 0x01
/* Error resilient mode enabled flag */
#define V4L2_VP9_FRAME_HDR_FLAG_ERR_RES	0x02
#define V4L2_VP9_FRAME_HDR_FLAG_FRAME_INTRA 0x04
#define V4L2_VP9_FRAME_HDR_ALLOW_HIGH_PREC_MV 0x08
#define V4L2_VP9_FRAME_HDR_REFRESH_FRAME_CTX 0x10
#define V4L2_VP9_FRAME_HDR_PARALLEL_DEC_MODE 0x20
struct v4l2_ctrl_vp9_frame_hdr {
  __u8 profile;
  /* 0: keyframe, 1: non-keyframe */
  __u8 frame_type;

  __u8 bit_depth;
  __u8 color_space;
  __u8 color_range;
  __u8 subsampling_x;
  __u8 subsampling_y;

  __u32 frame_width;
  __u32 frame_height;
  __u32 render_width;
  __u32 render_height;

  __u8 reset_frame_context;

  __u8 interpolation_filter;
  __u8 frame_context_idx;

  struct v4l2_vp9_loop_filter_params lf_params;
  struct v4l2_vp9_quantization_params quant_params;
  struct v4l2_vp9_segmentation_params sgmnt_params;

  __u8 tile_cols_log2;
  __u8 tile_rows_log2;

  __u16 header_size_in_bytes;

  __u8 flags;
};

struct v4l2_vp9_reference_frame {
  /* v4l2_buffer index */
  __u32 buf_index;

  __u32 frame_width;
  __u32 frame_height;
  __u8 bit_depth;
  __u8 subsampling_x;
  __u8 subsampling_y;
};

struct v4l2_ctrl_vp9_decode_param {
  /* v4l2_buffer index for all reference frames (frame slots). */
  __u32 ref_frames[8];

  /* Active reference frames, [0]: last, [1]: golden, [2]: altref */
  struct v4l2_vp9_reference_frame active_ref_frames[3];
};

struct v4l2_vp9_entropy_ctx {
  __u8 tx_probs_8x8[2][1];
  __u8 tx_probs_16x16[2][2];
  __u8 tx_probs_32x32[2][3];

  __u8 coef_probs[4][2][2][6][6][3];
  __u8 skip_prob[3];
  __u8 inter_mode_probs[7][3];
  __u8 interp_filter_probs[4][2];
  __u8 is_inter_prob[4];

  __u8 comp_mode_prob[5];
  __u8 single_ref_prob[5][2];
  __u8 comp_ref_prob[5];

  __u8 y_mode_probs[4][9];
  __u8 uv_mode_probs[10][9];

  __u8 partition_probs[16][3];

  __u8 mv_joint_probs[3];
  __u8 mv_sign_prob[2];
  __u8 mv_class_probs[2][10];
  __u8 mv_class0_bit_prob[2];
  __u8 mv_bits_prob[2][10];
  __u8 mv_class0_fr_probs[2][2][3];
  __u8 mv_fr_probs[2][3];
  __u8 mv_class0_hp_prob[2];
  __u8 mv_hp_prob[2];
};

/* Entropy context state for current frame (frame_context_idx). */
struct v4l2_ctrl_vp9_entropy {
  __u8 tx_mode;
  __u8 reference_mode;

  /* Entropy context after load_probs2(). */
  struct v4l2_vp9_entropy_ctx initial_entropy_ctx;

  /*
   * Entropy context for the current decoding state: when passed to the
   * driver, contains the state of initial_entropy_ctx after parsing the
   * compressed header. After decoding is done (after vb2_buffer_done() is
   * called on the associated buffer), state as after refresh_probs().
   */
  struct v4l2_vp9_entropy_ctx current_entropy_ctx;
};

#endif  // V4L2_CONTROLS_CUSTOM_H_
