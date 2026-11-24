# Symbol map — scoped assert strings → functions

The binary contains 482 `"Class::method"`-style assertion strings (release
build; the PS2 AOK.ELF has many more, plus source file names). Each string is
referenced near the code that implements it, giving us free function names.

Method: scan `.rdata`/`.data` for strings matching `^[A-Za-z_]\w*::\w+$`,
collect code xrefs, map to containing functions.

50 strings resolve to functions (below). The rest (432) have no direct code
xref — they are likely referenced via computed addresses or belong to dead/
inlined code paths; see `docs/symbol_map_raw.txt` for the full dump.

## Resolved

| String address | Identifier | Function(s) |
|---|---|---|
| 0x64d8c0 | `basegame::setup_fonts` | `sub_41E760` |
| 0x652138 | `diam_map::draw` | `sub_444370` |
| 0x652148 | `diam_map::clear_image` | `sub_444540` |
| 0x652160 | `diam_map::draw_all_tiles` | `sub_4446D0` |
| 0x65217c | `diam_map::draw_explored_tiles` | `sub_444740` |
| 0x65219c | `diam_map::draw_selected_area` | `sub_444C90` |
| 0x6521bc | `diam_map::draw_objects` | `sub_444D30` |
| 0x652654 | `TribeTechHelpScreen::draw_node_text` | `sub_457760` |
| 0x652678 | `TribeTechHelpScreen::draw_node_pic` | `sub_457760` |
| 0x65269c | `TribeTechHelpScreen::draw_background_art` | `sub_457EC0` |
| 0x6526c8 | `TribeTechHelpScreen::draw_lines` | `sub_458120` |
| 0x6526e8 | `TribeTechHelpScreen::draw_highlight` | `sub_458960` |
| 0x652740 | `TribePopUpHelp::draw_node` | `sub_45AFE0` |
| 0x65275c | `TribePopUpHelp::draw` | `sub_45AFE0` |
| 0x652774 | `TribePopUpHelp::draw_border` | `sub_45B330` |
| 0x65320c | `mouseptr::LoadCursors` | `sub_48A8C0` |
| 0x653248 | `mouseptr::draw` | `sub_48B000` |
| 0x653258 | `mouseptr::poll` | `sub_48B5B0` |
| 0x653614 | `panel_ez::setup_shadow_area` | `sub_4A2D50` |
| 0x653640 | `panel_ez::draw_background2` | `sub_4A2F90` |
| 0x65365c | `panel_ez::draw_background` | `sub_4A2F90` |
| 0x6536d8 | `pnl_btn::draw2` | `sub_4AFAC0` |
| 0x6536e8 | `pnl_btn::draw` | `sub_4AFAC0` |
| 0x653704 | `pnl_edit::draw` | `sub_4B4030` |
| 0x653714 | `pnl_inp::draw` | `sub_4B5040` |
| 0x653724 | `pnl_lst::draw` | `sub_4B6330` |
| 0x653734 | `pnl_lst::draw_highlight_bar` | `sub_4B6560` |
| 0x653780 | `pnl_msg::draw` | `sub_4B7170` |
| 0x653790 | `pnl_msg::render_to_image_buffer` | `sub_4B7850` |
| 0x6537c0 | `pnl_pic::draw` | `sub_4B8580` |
| 0x6537d0 | `pnl_scbr::draw` | `sub_4B9470, sub_4B9600` |
| 0x6537e0 | `pnl_txt::word_wrap_append` | `sub_4BA810` |
| 0x653860 | `pnl_txt::force_draw` | `sub_4BC170` |
| 0x653874 | `pnl_txt::draw` | `sub_4BC260` |
| 0x653884 | `pnl_txt::draw_background2` | `sub_4BC360` |
| 0x6538a0 | `pnl_txt::draw_background` | `sub_4BC360` |
| 0x6538bc | `pnl_txt::draw_border` | `sub_4BC560` |
| 0x6538d4 | `pnl_txt::get_text_rect` | `sub_4BD6A0` |
| 0x6541a0 | `scr_ach::draw` | `sub_4D2900` |
| 0x6542b0 | `scr_cred::draw` | `sub_4D6B20` |
| 0x65449c | `scr_game::draw4` | `sub_4E1AC0` |
| 0x6544ac | `scr_game::draw3` | `sub_4E1AC0` |
| 0x6544bc | `scr_game::draw2` | `sub_4E1AC0` |
| 0x6544cc | `scr_game::draw` | `sub_4E1AC0` |
| 0x655378 | `scr_multim::pe` | `sub_501F70` |
| 0x6553b0 | `TRIBE_Screen_Options::draw` | `sub_503FE0` |
| 0x655464 | `scr_sed::draw` | `sub_50D4C0` |
| 0x655ab4 | `scr_vc::draw` | `sub_51E5D0` |
| 0x655bc4 | `stat_obj::draw_frame_3d_square_back` | `sub_5283B0` |
| 0x655be8 | `stat_obj::draw_frame_3d_square_front` | `sub_528570` || 0x64d8c0 | `basegame::setup_fonts` | `sub_41E760` |
| 0x652138 | `diam_map::draw` | `sub_444370` |
| 0x652148 | `diam_map::clear_image` | `sub_444540` |
| 0x652160 | `diam_map::draw_all_tiles` | `sub_4446D0` |
| 0x65217c | `diam_map::draw_explored_tiles` | `sub_444740` |
| 0x65219c | `diam_map::draw_selected_area` | `sub_444C90` |
| 0x6521bc | `diam_map::draw_objects` | `sub_444D30` |
| 0x652654 | `TribeTechHelpScreen::draw_node_text` | `sub_457760` |
| 0x652678 | `TribeTechHelpScreen::draw_node_pic` | `sub_457760` |
| 0x65269c | `TribeTechHelpScreen::draw_background_art` | `sub_457EC0` |
| 0x6526c8 | `TribeTechHelpScreen::draw_lines` | `sub_458120` |
| 0x6526e8 | `TribeTechHelpScreen::draw_highlight` | `sub_458960` |
| 0x652740 | `TribePopUpHelp::draw_node` | `sub_45AFE0` |
| 0x65275c | `TribePopUpHelp::draw` | `sub_45AFE0` |
| 0x652774 | `TribePopUpHelp::draw_border` | `sub_45B330` |
| 0x65320c | `mouseptr::LoadCursors` | `sub_48A8C0` |
| 0x653248 | `mouseptr::draw` | `sub_48B000` |
| 0x653258 | `mouseptr::poll` | `sub_48B5B0` |
| 0x653614 | `panel_ez::setup_shadow_area` | `sub_4A2D50` |
| 0x653640 | `panel_ez::draw_background2` | `sub_4A2F90` |
| 0x65365c | `panel_ez::draw_background` | `sub_4A2F90` |
| 0x6536d8 | `pnl_btn::draw2` | `sub_4AFAC0` |
| 0x6536e8 | `pnl_btn::draw` | `sub_4AFAC0` |
| 0x653704 | `pnl_edit::draw` | `sub_4B4030` |
| 0x653714 | `pnl_inp::draw` | `sub_4B5040` |
| 0x653724 | `pnl_lst::draw` | `sub_4B6330` |
| 0x653734 | `pnl_lst::draw_highlight_bar` | `sub_4B6560` |
| 0x653780 | `pnl_msg::draw` | `sub_4B7170` |
| 0x653790 | `pnl_msg::render_to_image_buffer` | `sub_4B7850` |
| 0x6537c0 | `pnl_pic::draw` | `sub_4B8580` |
| 0x6537d0 | `pnl_scbr::draw` | `sub_4B9470, sub_4B9600` |
| 0x6537e0 | `pnl_txt::word_wrap_append` | `sub_4BA810` |
| 0x653860 | `pnl_txt::force_draw` | `sub_4BC170` |
| 0x653874 | `pnl_txt::draw` | `sub_4BC260` |
| 0x653884 | `pnl_txt::draw_background2` | `sub_4BC360` |
| 0x6538a0 | `pnl_txt::draw_background` | `sub_4BC360` |
| 0x6538bc | `pnl_txt::draw_border` | `sub_4BC560` |
| 0x6538d4 | `pnl_txt::get_text_rect` | `sub_4BD6A0` |
| 0x6541a0 | `scr_ach::draw` | `sub_4D2900` |
| 0x6542b0 | `scr_cred::draw` | `sub_4D6B20` |
| 0x65449c | `scr_game::draw4` | `sub_4E1AC0` |
| 0x6544ac | `scr_game::draw3` | `sub_4E1AC0` |
| 0x6544bc | `scr_game::draw2` | `sub_4E1AC0` |
| 0x6544cc | `scr_game::draw` | `sub_4E1AC0` |
| 0x655378 | `scr_multim::pe` | `sub_501F70` |
| 0x6553b0 | `TRIBE_Screen_Options::draw` | `sub_503FE0` |
| 0x655464 | `scr_sed::draw` | `sub_50D4C0` |
| 0x655ab4 | `scr_vc::draw` | `sub_51E5D0` |
| 0x655bc4 | `stat_obj::draw_frame_3d_square_back` | `sub_5283B0` |
| 0x655be8 | `stat_obj::draw_frame_3d_square_front` | `sub_528570` |

## Unresolved (no direct xref)

See `symbol_map_raw.txt`. Notable `NO-XREF` identifiers include the
`tpnl_*` (in-game HUD panel) family and `view::draw*` siblings — most have a
sibling string that *does* resolve (e.g. `view::draw3` → `sub_5D46C0`), so the
family address range brackets the others.

## Cross-reference

Engine class vocabulary from the sibling projects is in
`docs/cross_references.md`. Correlations so far:

- `basegame::setup_fonts` → `sub_41E760` (also in app vtable `off_61DF78`+0x44)
- `diam_map::draw*` → `sub_444370..sub_444D30` (isometric diamond-map renderer)
- `mouseptr::*` → `sub_48A8C0/sub_48B000/sub_48B5B0` (cursor load/draw/poll)
- `pnl_*`, `panel_ez` → UI panel widgets (`sub_4A2D50..sub_4BD6A0`)
- `scr_game::draw*` → `sub_4E1AC0` (in-game screen draw, 4 variants)
- `TRIBE_Screen_Options::draw` → `sub_503FE0` (options screen)


## Engine-debug-string names (second harvest)

99 distinct functions own engine-identifying debug strings (RGE_/COMM:/GTD/UNLINK families, `data/engine_strings.json`). Key ones not already in the scoped-string table:

| Function | Identifying string(s) |
|---|---|
| `0x41bc80` `sub_41BC80` | 'Creating new RGE_Game_Info' |
| `0x424be0` `sub_424BE0` | 'COMM: Send msg to window WM_USER  Msg=%d  Param=%d ' |
| `0x424c20` `sub_424C20` | '!!! Buffer size failure (LARGE)' |
| `0x425750` `sub_425750` | 'COMM:  %s  Version... %s' |
| `0x4262e0` `sub_4262E0` | 'DropDeadPlayer() called from KillAnyMissingPlayers()' |
| `0x427080` `sub_427080` | "GTD: RX Ser#%d From P#%d T#%ld ToExecT#%d Cmd=%d '%c' Seq=%d" |
| `0x427600` `sub_427600` | 'ShuttingDown == TRUE!! EvaluatePlayerMessage NOT getting called!' |
| `0x428470` `sub_428470` | 'COMM: Send msg to window WM_USER  Msg=%d  Param=%d ' |
| `0x4284b0` `sub_4284B0` | 'DropDeadPlayer() called from MSGTYPE_KILL_PLAYER, player %d, on turn %d' |
| `0x428c20` `sub_428C20` | 'sizeof(MSGFORMAT_SENDSHAREDDATA)=%ld, sizeof(MINICOMMPLAYEROPTIONS)=%ld, PlayerOptions.DataSizeToFollow=%ld, m.Size=%ld' |
| `0x429a50` `sub_429A50` | 'COMM:Unknown system message. %d' |
| `0x42b0b0` `sub_42B0B0` | '+++!RGEGTD Store' |
| `0x42b1c0` `sub_42B1C0` | '!RGEGTD Ack' |
| `0x42b280` `sub_42B280` | '!RGEGTD RxAck' |
| `0x42b3f0` `sub_42B3F0` | '!RGEGTD SendStore' |
| `0x42baf0` `sub_42BAF0` | 'TX RGTGTD' |
| `0x42c2a0` `sub_42C2A0` | 'UNLINK Unknown' |
| `0x42d020` `sub_42D020` | 'Unlink from level [ %d ] Failed.\n Stopping ' |
| `0x42d6c0` `sub_42D6C0` | "SRVC-Gt'd" |
| `0x42f940` `sub_42F940` | 'DropDeadPlayer() called from Kick()' |
| `0x4302f0` `sub_4302F0` | 'targetfile %s' |
| `0x438a00` `sub_438A00` | 'MeOptimal: Buf=%3d Gran=%3d  Target FPS=%3d  My expect turn=%4dms' |
| `0x4647c0` `sub_4647C0` | 'RGE_GAME_INFO: Read version correctly' |
| `0x4bf310` `sub_4BF310` | 'RGE_RANDOM_MAP_MODULE::module completed with random: %d.' |
| `0x4d6120` `sub_4D6120` | 'scr_cred' |
| `0x4ea260` `sub_4EA260` | 'scr_hist' |
| `0x4f6080` `` | 'Select Tribe Screen' |
| `0x500940` `sub_500940` | 'scr_mm-bln' |
| `0x501120` `sub_501120` | 'scr_mm-pb' |
| `0x51cfe0` `sub_51CFE0` | 'scr_stms' |
| `0x52f480` `sub_52F480` | 'TribeBuildingObj ROO 1.' |
| `0x556d50` `sub_556D50` | 'LARGE-MAP' |
| `0x5575d0` `sub_5575D0` | 'sn-target-evaluation-in-progress' |
| `0x570bf0` `sub_570BF0` | '      Tasking group to attack targetID=%d.' |
| `0x571760` `sub_571760` | 'No Target' |
| `0x571b70` `sub_571B70` | 'No Target' |
| `0x5a0640` `sub_5A0640` | 'No Target, ' |
| `0x5a6030` `sub_5A6030` | 'tpnl_inv::draw' |
| `0x5a6b60` `sub_5A6B60` | 'tpnl_inv::draw' |
| `0x5a7950` `sub_5A7950` | 'tpnl_obj::draw' |
| `0x5a9040` `sub_5A9040` | 'tpnl_obj::draw_score' |
| `0x5a92c0` `sub_5A92C0` | 'tpnl_obj::draw_item' |
| `0x5a9580` `sub_5A9580` | 'tpnl_obj::draw_item' |
| `0x5a9690` `sub_5A9690` | 'tpnl_obj::draw_item' |
| `0x5a9780` `sub_5A9780` | 'tpnl_obj::draw_research' |
