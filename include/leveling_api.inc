#if defined _levelin_api_included
	#endinput
#endif
#define _levelin_api_included

forward OnLevelUp(index, new_level);


/** Sets player exp.

    @param index Connected player index (1-32)
    @param exp Value to be set. Negative values are allowed.

    @return 1 on success, 0 on error.
 */
native set_user_exp(index, exp);

/** Sets player level.

    @param index Connected player index (1-32)
    @param level Value to be set. Only values in range 1-get_max_level() are allowed.
    @param dispatch Whether to dispatch event of leveling up.

    @return 1 on success, 0 on error.
 */
native set_user_lvl(index, level, bool:dispatch = false);

/** Gets player exp.

    @param index Connected player index (1-32)

    @return User exp or -1 on failure.
 */
native get_user_exp(index);

/** Gets player level.

    @param index Connected player index (1-32)

    @return User level or -1 on failure.
 */
native get_user_lvl(index);

/** Gets exp required to level up based on player index.

    @param index Connected player index (1-32)

    @return Exp required or -1 on failure.
 */
native get_required(index);

/** Gets exp required to level up based on given level.

    @param level A valid 1-get_max_level() value

    @return Exp required or -1 on failure.
 */
native get_required_by_lvl(level);

/** Gets current max level

    @return Max level
 */
native get_max_level();

/** Gets exp range for specified level

    @param level A valid 1-get_max_level() value
    @param out A 2-cell array to copy the ranges into

    @return 1 on success, 0 on failure
 */
native get_exp_range(level, out[2]);

/** Gets ap reward for specified level

    @param level A valid 1-get_max_level() value

    @return -1 on failure, ap amount on success
 */
native get_lvl_ap(level);

/** Gets armor reward for specified level

    @param level A valid 1-get_max_level() value

    @return -1 on failure, armor amount on success
 */
native get_lvl_armor(level);

/** Gets hp reward for specified level

    @param level A valid 1-get_max_level() value

    @return -1 on failure, hp amount on success
 */
native get_lvl_hp(level);

/** Saves level-related data (exp, level) to nvault.

    @noparams
    @return 1 on success, 0 on failure
 */
native save_leveling_data();