/* CSWM Incude File */

#if defined CSWM
    #endinput
#endif
#define CSWM

#if AMXX_VERSION_NUM >= 175
    #pragma reqlib cswm
#if !defined AMXMODX_NOAUTOLOAD
    #pragma loadlib cswm
#endif
#else
    #pragma library cswm
#endif

#if !defined BIT
    #define BIT(%1) (1 << %1)
#endif

#include <cswm_const>

/**
 * Creates a new weapon definition with the specified model, type, and name.
 *
 * @note This function is used to retrieve an existing weapon definition or create a new one if it does not exist.
 *
 * @param model         Model of the weapon. Used to retrieve an existing weapon definition or create a new one if it does not exist.
 * @param type          Type of the weapon. Used to specify the weapon type. See WType enum in cswm_const.inc
 *                      Valid values are:
 *                      0 - Pistol or P228
 *                      1 - Shotgun or XM1014
 *                      2 - Rifle or AK47
 *                      3 - Sniper or AWP
 * @param name          Name of the weapon. This parameter is not used internally but can be retrieved through plugins. It is useful for menus.
 *
 * @return              The index of the created weapon definition.
 */
native CreateWeapon(const model[], any:type, const name[]);

/**
 * Creates an ammo with the specified cost, amount, and maximum count of ammunition.
 *
 * @param cost          The cost of the ammo in $.
 * @param amount        The count of ammunition. This is the count of ammo which will be given to the player after buying.
 * @param max           The maximum count of ammunition. The player can't buy more than this count of ammo.
 *
 * @return              The ammo index.
 */
native CreateAmmo(cost, amount, max);

/**
 * Builds the view model, player view weapon model, and world model of the weapon with the specified index.
 *
 * @param weapon        The index of the weapon.
 * @param vModel        The view model of the weapon. Following models can be precached through custom paths.
 * @param pModel        The player view weapon model of the weapon.
 *                      Player view weapon model is the type of weapon model which is shown when another player is holding it.
 * @param wModel        The world model of the weapon. World model of the weapon is shown when the weapon is dropped.
 *
 * @noreturn
 */
native BuildWeaponModels(weapon, const vModel[], const pModel[], const wModel[]);

/**
 * Builds the fire/shoot sound for the specified weapon.
 *
 * @param weapon        The index of the weapon.
 * @param sound         The fire/shoot sound.
 *                      The fire sound should be in the path: 'cstrike/sound/'.
 *                      For example, the path of the fire sound 'weapons/ak47-1.wav' is 'cstrike/sound/weapons/ak47-1.wav'.
 *
 * @noreturn
 */
native BuildWeaponFireSound(weapon, const sound[]);

/**
 * Builds the weapon list for the specified weapon.
 *
 * @param weapon        The index of the weapon.
 * @param weaponList    The name of the weapon list. 
 *                      The weapon list is a pack of information that is used to show the weapon on the HUD.
 *                      The weapon list file should be in the following path: 'cstrike/sprites/'.
 *                      The file type of the weapon list is '.txt', which should not be added in the name.
 *                      For example, the path of the weapon list 'weapon_ak47' is 'cstrike/sprites/weapon_ak47.txt'.
 *                      However, the weapon list is a path, so you can put a folder in the name. (Example: 'cswm/weapon_ak47')
 *
 * @noreturn
 */
native BuildWeaponList(weapon, const weaponList[]);

/**
 * Builds the ammunition of a weapon.
 *
 * @param weapon        Index of the weapon.
 * @param Clip          Weapon clip. Clip is count of ammo that can be drained from weapon before next reload.
 * @param ammoID        Ammo index of the weapon. Ammo index (PrimaryAmmoType) is type of ammo that is used for current weapon.
 *                      Ammo index is required to set which ammo type should be used from player's ammo list.
 *
 * @noreturn
 */
native BuildWeaponAmmunition(weapon, Clip, any:ammoID);

/**
 * Builds the deploy animation of a weapon.
 *
 * @param weapon        Index of the weapon.
 * @param animation     Animation index of the weapon. Use model viewer to detect current animation index.
 *                      If you are not able to do this set animation to 0.
 *                      Setting animation to 0 will result auto detecting it. (However this is not 100% accurate)
 * @param duration      Duration time of animation. This is time after player is able to shoot from weapon.
 *                      If you want exact time then set this to 0.0.
 *
 * @noreturn
 */
native BuildWeaponDeploy(weapon, animation, Float:duration);

/**
 * Builds a primary attack for a weapon.
 *
 * @param weapon        Index of the weapon.
 * @param delay         Delay of the weapon. Time after player is able to shoot again.
 *                      If you want to get original time of specified weapon use 'GetWeaponDefaultDelay'.
 * @param damage        Damage multiplier of the weapon.
 *                      1.0 will not damage enemies by 1.0, it will multiply current weapons damage by 1.0.
 *                      Current weapon in this case is weapon which is one of default weapons.
 *                      Current weapon depends on weapon type specified when creating weapon.
 * @param recoil        Recoil multiplier of weapon.
 *                      This is multiplier, same as 'Damage', but it is controlling spreading and accuracy.
 * @param animation     Animation of shoot. Shoot animations can be infinite.
 *                      If your weapon has shoot animations 3,4 and 5 then pass them as 3,4,5.
 *                      If you can not detect shoot animations then do not write anything.
 *                      Nothing as parameter will result auto detecting shoot animations. (Not 100% Accurate)
 *
 * @noreturn
 */
native BuildWeaponPrimaryAttack(weapon, Float:delay, Float:damage, Float:recoil, any:...);

/**
 * Builds a reload animation for a weapon.
 *
 * @param weapon        Index of the weapon.
 * @param animation     Animation of reload. Set to 0 to auto detect.
 * @param duration      Time after shoot is allowed. Set to 0.0 to auto detect.
 *
 * @noreturn
 */
native BuildWeaponReload(weapon, animation, Float:duration);

/**
 * Builds a reload animation for a shotgun weapon.
 *
 * @param weapon        Index of the weapon.
 * @param duration      Duration of reload. duration is single clip insert time. 0.55 should be default reload time.
 * @param type          Type of reload.
 *                      0 - Reload as M3;
 *                      1 - Reload as XM1014;
 *                      2 - Reload as anything other, like Rifle.
 *
 * @noreturn
 */
native BuildWeaponReloadShotgun(weapon, Float:duration, any:type);

/**
 * Builds weapon flags for a weapon.
 *
 * @param weapon        Index of the weapon.
 * @param flags         Flag bitsum of weapon flags. Check WFlag enum in 'cswm_const.inc'.
 *
 * @noreturn
 */
native BuildWeaponFlags(weapon, any:flags);

/**
 * Builds a secondary attack for a weapon.
 *
 * @param weapon        Index of the weapon.
 * @param type          Type of attack2. Check WAttack2 enum in 'cswm_const.inc'.
 * @param ...           Settings of current attack2 type. Check 'cswm_const.inc' for more details.
 *
 * @noreturn
 */
native BuildWeaponSecondaryAttack(weapon, any:type, any:...);

/**
 * Builds the maximum speed for a weapon.
 *
 * @param weapon        Index of the weapon.
 * @param maxSpeed      Speed when holding weapon.
 *
 * @noreturn
 */
native BuildWeaponMaxSpeed(weapon, Float:maxSpeed);

/**
 * Builds weapon primary attack specifications without animation.
 *
 * @param weapon        Index of the weapon.
 * @param delay         Delay before next shoot.
 * @param recoil        Accuracy, spread multiplier.
 * @param damage        Damage multiplier.
 *
 * @noreturn
 */
native BuildWeaponSpecs(weapon, Float:delay, Float:recoil, Float:damage);

/**
 * Checks a weapon's animations and other parameters that are not valid.
 * Includes clip, ammo type, fire sound, speed, delay.
 *
 * @param weapon        Index of the weapon.
 *
 * @noreturn
 */
native CheckWeaponParams(weapon);

/**
 * Registers a weapon forward event.
 *
 * @param weapon        Index of the weapon.
 * @param forward       Forward index. This is event which will be hooked. Check WForward enum in 'cswm_const.inc'.
 * @param callback      Callback function to be executed when the forward event is triggered.
 *
 * @noreturn
 */
native RegisterWeaponForward(weapon, any:forward, const Callback[]);

/**
 * Precaches specified weapon's model's sounds. Same as sv_auto_precache_sounds_in_models, but precache is done when function is called.
 *
 * @param weapon        Index of the weapon.
 *
 * @noreturn
 */
native PrecacheWeaponModelSounds(weapon);

/**
 * Precaches specified weapon's own hud's sprites.
 *
 * @param weapon        Index of the weapon.
 *
 * @noreturn
 */
native PrecacheWeaponListSprites(weapon);

/**
 * Finds a weapon by its model.
 *
 * @param model         Model of the weapon. Model is assigned when creating weapon. ('CreateWeapon' first parameter)
 *
 * @return              Index of the weapon.
 */
native FindWeaponByModel(const name[]);

/**
 * Finds a weapon by its name.
 *
 * @param name          Name of the weapon. Name is assigned when creating weapon. ('CreateWeapon' third parameter)
 *
 * @return              Index of the weapon.
 */
native FindWeaponByName(const name[]);

/**
 * Gives a weapon to a player by its name.
 *
 * @param playerID      Player index. Player which will get the weapon.
 * @param name          Name of the weapon. Name is 3rd parameter in 'CreateWeapon'.
 *
 * @noreturn
 */
native GiveWeaponByName(playerID, const name[]);

/**
 * Gives a weapon to a player by its ID.
 *
 * @param playerID      Player index. Player which will get the weapon.
 * @param weapon        Index of the weapon.
 *
 * @noreturn
 */
native GiveWeaponByID(playerID, weapon);

/**
 * Gets data for a weapon.
 *
 * @param weapon        Index of the weapon.
 * @param data          Weapon data. Check WData enum in 'cswm_const.inc'.
 *                      If data is string then 3rd parameter is string and 4th is string length.
 *
 * @return              Data for the weapon.
 */
native any:GetWeaponData(weapon, any:data, any:...);

/**
 * Sends a weapon animation to the weapon entity.
 *
 * @param weaponEnt     Weapon entity. weapon entity is weapon held by the player.
 * @param animation     Animation which should be played.
 *
 * @noreturn
 */
native SendWeaponAnim(weaponEnt, animation);

/**
 * Creates a projectile with the specified model, gravity, speed, duration, and callback function.
 *
 * @note The projectile model will be precached.
 *
 * @param model         The model of the projectile.
 * @param gravity       The gravity of the projectile (1.0=Normal).
 * @param speed         The speed of the projectile (250.0=PlayerMaxSpeed).
 * @param callback      The callback function to be executed when the projectile touches something.
 * @param duration      The duration of the projectile. This is the fifth parameter of the native which will set the duration of the projectile. If the projectile is launched through 'ShootProjectileContact', then duration is unused.
 *
 * @return              The projectile index.
 */
native CreateProjectile(const model[], Float:gravity, Float:speed, const callback[], Float:duration = 0.0);

/**
 * Creates an effect with the specified model, speed, duration, and callback function.
 *
 * @note The effect model will be precached.
 *
 * @param model         The model of the effect.
 * @param speed         The speed of the effect.
 * @param callback      The callback function to be executed when the effect expires.
 * @param duration      The duration before the effect expires after firing.
 *
 * @return              The effect index.
 */
native CreateEffect(const model[], Float:speed, const callback[], Float:duration);

/**
 * Shoots a timed projectile from the launcher entity and removes it after it expires.
 *
 * @param launcher      The launcher entity. It should be a player.
 * @param projectile    The index of the projectile.
 *
 * @noreturn
 */
native ShootProjectileTimed(launcher, projectile);

/**
 * Shoots a projectile from the launcher entity that should be manually removed.
 *
 * @param launcher      The launcher entity. It should be a player.
 * @param projectile    The index of the projectile.
 *
 * @noreturn
 */
native ShootProjectileContact(launcher, projectile);

/**
 * Shoots an effect from the launcher entity and removes it after it expires.
 *
 * @param launcher      The launcher entity. It should be a player.
 * @param effect        The index of the effect.
 *
 * @noreturn
 */
native ShootEffect(launcher, effect);

/**
 * Gives the specified amount of ammo to the player entity.
 *
 * @param playerID      The player entity.
 * @param ammoID        The index of the ammo.
 * @param amount        The amount of ammo to be given.
 *
 * @noreturn
 */
native GiveAmmo(playerID, ammoID, amount);

/**
 * Sets the name of the specified ammo and makes it searchable.
 *
 * @param ammo          The index of the ammo.
 * @param name          The name of the ammo.
 *
 * @noreturn
 */
native SetAmmoName(ammo, const name[]);

/**
 * Finds the ammo index by searching for the specified ammo name.
 *
 * @param name          The ammo name to be searched.
 *
 * @return              The ammo index.
 */
native FindAmmoByName(const name[]);

/**
 * Returns the count of created weapons.
 *
 * @return              The count of created weapons.
 */
native GetWeaponCount();

/**
 * Gets the name of the specified weapon and stores it in the output variable.
 *
 * @param weapon        The index of the weapon.
 * @param output        The variable where the name will be stored.
 * @param length        The length of the variable.
 *
 * @return              True or 1 on success.
 */
native GetWeaponName(weapon, const output[], length);

/**
 * Gets the model of the specified weapon and stores it in the output variable.
 *
 * @param weapon        The index of the weapon.
 * @param output        The variable where the model will be stored.
 * @param length        The length of the variable.
 *
 * @return              True or 1 on success.
 */
native GetWeaponModel(weapon, const output[], length);

/**
 * Sets the path that will be added on while precaching the weapon.
 *
 * @note This only works when the user has not used 'BuildWeaponModels'.
 *       Precached weapon's path looks like: 'models/<Path Addon>/<weapon Model>/<V, P or W>.mdl'
 *
 * @param path          The path that will be added on.
 *
 * @noreturn
 */
native SetWeaponPathAddon(const path[]);

/**
 * Gets the weapon's flags bit sum using the weapon index.
 *
 * @param weapon        The index of the weapon.
 *
 * @return              The weapon's flags bit sum.
 */
native GetWeaponFlags(weapon);

/**
 * Creates an explosion at the specified origin with the specified flags.
 *
 * @param origin        The origin of the explosion.
 * @param flags         Same as TE_EXPFLAG_* flags. The explosion also creates TE_WORLDDECAL and TE_SMOKE.
 *
 * @noreturn
 */
native CreateExplosion(Float:origin[3], flags);

/**
 * Applies radius damage at the specified center with the specified radius, damage amount, inflictor, attacker, damage bits, and flags.
 *
 * @param origin        The center of radius damage.
 * @param radius        The damage radius.
 * @param damage        The damage amount.
 * @param inflictor     The inflictor entity.
 * @param attacker      The attacker entity.
 * @param damageBits    The damage bit sum.
 * @param flags         The radius damage flags. See RDFlag enum in 'cswm_const.inc'.
 *
 * @noreturn
 */
native RadiusDamageEx(Float:origin[3], Float:radius, Float:damage, inflictor, attacker, damageBits, RDFlag:flags);

/**
 * Deals cleave damage from the specified origin and angles with the specified field of view and range of view.
 *
 * @param origin        The center of the cleave damage.
 * @param vangles       The angles of the damage.
 * @param fov           The field of view of the damage.
 * @param accurate      If set, will lower the range.
 * @param damage        The damage of the cleave.
 * @param radius        The radius of the cleave (maximum length from origin).
 * @param inflictor     The inflictor entity.
 * @param attacker      The attacker entity.
 * @param damageType    The damage bits sum.
 *
 * @noreturn
 */
native CleaveDamage(Float:origin[3], Float:vangles[3], Float:fov, bool:accurate, Float:damage, Float:radius, inflictor, attacker, damageType);

/**
 * Deals cleave damage from the player entity with the specified damage and radius.
 *
 * @param playerID      The player entity.
 * @param damage        The damage of cleave.
 * @param radius        The radius of cleave (maximum length from player). Accurate = FALSE, DamageType = DMG_SLASH
 *
 * @noreturn
 */
native CleaveDamageByPlayer(playerID, Float:damage, Float:radius);

/**
 * Checks if the player can perform a primary attack through the specified weapon entity.
 *
 * @param entity        The weapon entity.
 *
 * @return              True if the player is able to shoot, otherwise false.
 */
native CanPrimaryAttack(entity);

/**
 * Sets the duration after which the player will be able to shoot again and updates the next idle animation time for the weapon entity.
 *
 * @param entity                The weapon entity.
 * @param duration              The duration after which the player will be able to shoot again.
 * @param updateTimeWeaponIdle  Whether to update the next idle animation time.
 *
 * @noreturn
 */
native SetNextAttack(entity, Float:duration, bool:updateTimeWeaponIdle);

/**
 * Sets the idle animation for the specified weapon and sets the CustomIdleAnim flag to this weapon after using this native.
 *
 * @param weapon        The index of the weapon.
 * @param animation     The animation index.
 *
 * @noreturn
 */
native SetWeaponIdleAnim(weapon, animation);

/**
 * Gets the path addon value and returns the length of the output string.
 *
 * @param output        The output string variable.
 * @param length        The length of the output string.
 *
 * @return              The path addon value.
 */
native GetWeaponPathAddon(const output[], length);

/**
 * Sets the view model of the specified player's
 *
 * @param playerID      The player entity.
 * @param viewModel     The view model of the weapon as an integer and not a string.
 *
 * @noreturn
 */
native SetPlayerViewModel(playerID, viewModel);

/**
 * Sets the weapon model of the specified player's
 *
 * @param playerID      The player entity.
 * @param weapModel     The weapon model of the weapon as an integer and not a string.
 *
 * @noreturn
 */
native SetPlayerWeapModel(playerID, weapModel);

/**
 * Precaches the specified weapon model.
 *
 * @param model         The model to be precached.
 *
 * @return              The model as an integer number.
 */
native PrecacheWeaponModelEx(const model[]);

/**
 * Sets the animation of the specified player entity with the specified animation index, activity, and frame rate.
 *
 * @param playerID      The player entity.
 * @param animation     The animation index.
 * @param activity      The activity. Check the ACT enum in 'cswm_const.inc' for the activity enum.
 * @param frameRate     The frame rate of the animation. The default is 1.0.
 *
 * @noreturn
 */
native SetAnimation(playerID, animation, any:activity, Float:frameRate);

/**
 * Gets the default delay of the specified weapon ID.
 *
 * @param weaponID      The weapon ID. weapon ID is CSW_*.
 *
 * @return              The weapon delay.
 */
native Float:GetWeaponDefaultDelay(weaponID);

/**
 * Gets the duration of the specified weapon animation.
 *
 * @param weapon        The index of the weapon.
 * @param animation     The animation index.
 *
 * @return              The duration of the weapon animation.
 */
native Float:GetWeaponAnimDuration(weapon, animation);

/**
 * Builds and precaches the model for the specified weapon.
 *
 * @param weapon        The index of the weapon.
 * @param modelID       The ID of the model. 0=View|1=Weap|2=World|3=WeaponList.
 * @param model         The model that should be assigned and precached. Note that the model can be a weaponlist (sprite).
 *
 * @noreturn
 */
native BuildWeaponModel(weapon, modelID, const model[]);

/**
 * Builds and precaches the model for the specified weapon.
 *
 * @param weapon        The index of the weapon.
 * @param modelID       The ID of the model. 0=View|1=Weap|2=World|3=WeaponList.
 * @param model         The model (integer) that should be assigned and precached. Note that the model can be a weaponlist (sprite).
 *
 * @noreturn
 */
native BuildWeaponModelEx(weapon, modelID, model);

/**
 * Returns the weapon clip.
 *
 * @note If the weapon is custom and has SoloClip enabled, then it will return the player's ammo.
 *
 * @param weaponEnt     The weapon entity.
 *
 * @return              The weapon clip.
 */
native GetWeaponClip(weaponEnt);

/**
 * Sets the clip amount of the specified weapon entity.
 *
 * @note If the weapon is custom and has SoloClip enabled, this native will set the player's ammo to this value.
 *
 * @param weaponEnt     The weapon entity.
 * @param amount        The amount of clip.
 *
 */
native SetWeaponClip(weaponEnt, amount);

/**
 * Sets the status icon message to show the specified number for the specified player entity.
 *
 * @param playerID      The player entity.
 * @param type          The type of the status icon. Type is the status icon message 1st argument.
 * @param number        The number to be shown. The maximum number is 9, and the minimum is 0.
 *
 * @noreturn
 */
native StatusIconNumber(playerID, type, number);

/**
 * Determines whether the specified weapon entity is custom or not.
 *
 * @param weaponEnt     The weapon entity.
 *
 * @return              Whether the weapon is custom or not.
 */
native IsCustomWeaponEntity(weaponEnt);

/**
 * Returns the weapon key if the specified weapon entity is custom, otherwise -1.
 *
 * @param weaponEnt     The weapon entity.
 *
 * @return              The weapon key if it's custom, otherwise -1.
 */
native GetWeaponEntityKey(weaponEnt);

/**
 * Returns the weapon entity data for the specified weapon entity and data type.
 * See WEData enum in 'cswm_const.inc'.
 *
 * @param weaponEnt     The weapon entity.
 * @param data          The weapon entity data.
 *
 * @return              The weapon entity data.
 */
native any:GetWeaponEntityData(weaponEnt, any:data);

/**
 * Sets the value of the specified data for the weapon entity.
 *
 * @param weaponEnt     The weapon entity.
 * @param data          The weapon entity data. See WEData enum in 'cswm_const.inc'.
 * @param value         The value of the data.
 *
 * @noreturn
 */
native SetWeaponEntityData(weaponEnt, any:data, value);

/**
 * Sets the submodel of the current weapon's world model when it is dropped.
 *
 * @param weapon        The index of the weapon.
 * @param index         The index of the body of the weapon world model.
 *
 * @noreturn
 */
native SetWeaponWBody(weapon, index);

/**
 * Sets the power of push for knockback and the Z axis power.
 *
 * @param pushPower     The power of push for knockback.
 * @param jumpPower     The Z axis power. Jump power will also be multiplied by push power.
 *
 * @noreturn
 */
native SetKnockbackInfo(Float:pushPower, Float:jumpPower);

/**
 * Applies knockback to the player entity.
 *
 * @param playerID      The player entity.
 * @param origin        The center of knockback.
 *
 * @noreturn
 */
native PlayerKockback(playerID, Float:origin[3]);

/**
 * Same as Ham_TakeDamage, but with a fix for custom weapon's damage.
 *
 * @param callback  The callback function to be executed.
 *
 * @noreturn
 */
native RegisterTakeDamageForward(const callback[]);
