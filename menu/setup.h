class CMenuSystem
{
public:
	CMenuSystem();
};

CMenuSystem::CMenuSystem()
{

	LWindow* mainWindow = new LWindow();
	mainWindow->SetSize(512, 512);
	mainWindow->SetPos(200, 200);
	mainWindow->SetTitle("LoliSmasher");

	LImage* banner = new LImage();
	banner->SetPos(256, -128); // ., 55 - 234
	banner->SetSize(256, 157); // 120, 234
	banner->SetImage(IDR_IMAGE1, "image");
	banner->SetParent(mainWindow);

	LImage* banner2 = new LImage();
	banner2->SetPos(0, -155);
	banner2->SetSize(178, 182);
	banner2->SetImage(IDR_IMAGE2, "image");
	banner2->SetParent(mainWindow);

	LTabPanel* tabProperty = new LTabPanel();
	tabProperty->SetParent(mainWindow);
	tabProperty->SetPos(10, 35);
	tabProperty->SetSize(512 - 20, 512 - 70);
	
	LBaseObject* aimbotTab = tabProperty->AddTab("Aimbot");
	
	LCheckBox* aimbotEnabled = new LCheckBox();
	aimbotEnabled->SetPos(10, 10);
	aimbotEnabled->SetVar(&CheatVariables::aimbot_enabled);
	aimbotEnabled->SetText("Aimbot Enabled");
	aimbotEnabled->SetParent(aimbotTab);

	LCheckBox* aimbotHitchance = new LCheckBox();
	aimbotHitchance->SetPos(300, 35);
	aimbotHitchance->SetVar(&CheatVariables::aimbot_hitchance);
	aimbotHitchance->SetText("Aimbot Hitchance");
	aimbotHitchance->SetParent(aimbotTab);
	
	LCheckBox* aimbotRage = new LCheckBox();
	aimbotRage->SetPos(10, 35);
	aimbotRage->SetVar(&CheatVariables::aimbot_rage);
	aimbotRage->SetText("Aimbot Auto Fire");
	aimbotRage->SetParent(aimbotTab);

	LCheckBox* aimbotAutoWall = new LCheckBox();
	aimbotAutoWall->SetPos(10, 60);
	aimbotAutoWall->SetVar(&CheatVariables::aimbot_autowall);
	aimbotAutoWall->SetText("Auto Wall");
	aimbotAutoWall->SetParent(aimbotTab);

	/*
	LCheckBox* aimbotSmooth = new LCheckBox();
	aimbotSmooth->SetPos(10, 35);
	aimbotSmooth->SetVar(&CheatVariables::aimbot_smooth);
	aimbotSmooth->SetText("Smooth Aim");
	aimbotSmooth->SetParent(aimbotTab);

	LSlider* aimbotSmoothFactor = new LSlider();
	aimbotSmoothFactor->SetPos(10, 75);
	aimbotSmoothFactor->SetSize(512 - 40, 10);
	aimbotSmoothFactor->SetRange(0, 100);
	aimbotSmoothFactor->SetVar(&CheatVariables::aimbot_smoothFactor);
	aimbotSmoothFactor->SetText("Smooth Amount");
	aimbotSmoothFactor->SetParent(aimbotTab);

	LCheckBox* aimbotIgnoreTeam = new LCheckBox();
	aimbotIgnoreTeam->SetPos(10, 90);
	aimbotIgnoreTeam->SetVar(&CheatVariables::aimbot_ignoreTeam);
	aimbotIgnoreTeam->SetText("Ignore Team");
	aimbotIgnoreTeam->SetParent(aimbotTab);

	LCheckBox* aimbotIgnoreFriends = new LCheckBox();
	aimbotIgnoreFriends->SetPos(10, 115);
	aimbotIgnoreFriends->SetVar(&CheatVariables::aimbot_ignoreFriends);
	aimbotIgnoreFriends->SetText("Ignore Friends");
	aimbotIgnoreFriends->SetParent(aimbotTab);
	*/

	LCheckBox* aimbotTriggerEnabled = new LCheckBox();
	aimbotTriggerEnabled->SetPos(10, 85);
	aimbotTriggerEnabled->SetVar(&CheatVariables::aimbot_trigger);
	aimbotTriggerEnabled->SetText("Triggerbot Enabled");
	aimbotTriggerEnabled->SetParent(aimbotTab);

	LCheckBox* aimbotSilent = new LCheckBox();
	aimbotSilent->SetPos(300, 10);
	aimbotSilent->SetVar(&CheatVariables::aimbot_silent);
	aimbotSilent->SetText("Silent Aim (Client)");
	aimbotSilent->SetParent(aimbotTab);

	LCheckBox* aimbotTriggerKeyEnabled = new LCheckBox();
	aimbotTriggerKeyEnabled->SetPos(10, 110);
	aimbotTriggerKeyEnabled->SetVar(&CheatVariables::aimbot_triggerkey);
	aimbotTriggerKeyEnabled->SetText("TriggerKey Enabled");
	aimbotTriggerKeyEnabled->SetParent(aimbotTab);

	LComboBox* aimbotTriggerKey = new LComboBox();
	aimbotTriggerKey->SetPos(512 - 130, 110);
	aimbotTriggerKey->SetVar(&CheatVariables::aimbot_triggerkeykey);
	aimbotTriggerKey->SetText("Mouse 4");
	aimbotTriggerKey->AddOption("Mouse 4", VK_XBUTTON1);
	aimbotTriggerKey->AddOption("Mouse 2", VK_RBUTTON);
	aimbotTriggerKey->AddOption("Caps Lock", VK_CAPITAL);
	aimbotTriggerKey->SetParent(aimbotTab);

	/*
	LSlider* aimbotTriggerDelay = new LSlider();
	aimbotTriggerDelay->SetPos(10, 135);
	aimbotTriggerDelay->SetSize(512 - 40, 10);
	aimbotTriggerDelay->SetRange(0, 1000);
	aimbotTriggerDelay->SetVar(&CheatVariables::aimbot_triggerdelay);
	aimbotTriggerDelay->SetText("Triggerbot Delay (ms)");
	aimbotTriggerDelay->SetParent(aimbotTab);
	*/

	LSlider* aimbotWallAmount = new LSlider();
	aimbotWallAmount->SetPos(10, 155);
	aimbotWallAmount->SetSize(512 - 40, 10);
	aimbotWallAmount->SetRange(14, 100);
	aimbotWallAmount->SetVar(&CheatVariables::aimbot_wallamount);
	aimbotWallAmount->SetText("Auto Wall Amount");
	aimbotWallAmount->SetParent(aimbotTab);

	LSlider* aimbotTriggerBurst = new LSlider();
	aimbotTriggerBurst->SetPos(10, 185);
	aimbotTriggerBurst->SetSize(512 - 40, 10);
	aimbotTriggerBurst->SetRange(0, 1000);
	aimbotTriggerBurst->SetVar(&CheatVariables::aimbot_afterburst);
	aimbotTriggerBurst->SetText("Triggerbot Afterburst (ms)");
	aimbotTriggerBurst->SetParent(aimbotTab);

	LCheckBox* aimbotSmoothAim = new LCheckBox();
	aimbotSmoothAim->SetPos(10, 210);
	aimbotSmoothAim->SetVar(&CheatVariables::aimbot_smooth);
	aimbotSmoothAim->SetText("Smooth Aim");
	aimbotSmoothAim->SetParent(aimbotTab);

	LSlider* aimbotSmoothAimFactor = new LSlider();
	aimbotSmoothAimFactor->SetPos(10, 250);
	aimbotSmoothAimFactor->SetSize(512 - 40, 10);
	aimbotSmoothAimFactor->SetRange(0, 100);
	aimbotSmoothAimFactor->SetVar(&CheatVariables::aimbot_smoothFactor);
	aimbotSmoothAimFactor->SetText("Smooth Aim Speed");
	aimbotSmoothAimFactor->SetParent(aimbotTab);



	LBaseObject* visualTab = tabProperty->AddTab("Visual");

	LCheckBox* visualPlayerEsp = new LCheckBox();
	visualPlayerEsp->SetPos(10, 10);
	visualPlayerEsp->SetVar(&CheatVariables::visual_boxesp);
	visualPlayerEsp->SetText("Box ESP");
	visualPlayerEsp->SetParent(visualTab);

	/*
	LCheckBox* visualChickenEsp = new LCheckBox();
	visualChickenEsp->SetPos(10, 35);
	visualChickenEsp->SetVar(&CheatVariables::visual_chickenesp);
	visualChickenEsp->SetText("Draw Chickens");
	visualChickenEsp->SetParent(visualTab);
	*/

	LCheckBox* visualNameEsp = new LCheckBox();
	visualNameEsp->SetPos(10, 35);
	visualNameEsp->SetVar(&CheatVariables::visual_nameesp);
	visualNameEsp->SetText("Draw Names");
	visualNameEsp->SetParent(visualTab);

	/*
	LCheckBox* visualBoxEsp = new LCheckBox();
	visualBoxEsp->SetPos(10, 85);
	visualBoxEsp->SetVar(&CheatVariables::visual_boxesp);
	visualBoxEsp->SetText("Box ESP");
	visualBoxEsp->SetParent(visualTab);

	LCheckBox* visualFillBox = new LCheckBox();
	visualFillBox->SetPos(10, 110);
	visualFillBox->SetVar(&CheatVariables::visual_fillbox);
	visualFillBox->SetText("Fill Box");
	visualFillBox->SetParent(visualTab);

	LCheckBox* visual3DBox = new LCheckBox();
	visual3DBox->SetPos(10, 135);
	visual3DBox->SetVar(&CheatVariables::visual_use3dbox);
	visual3DBox->SetText("3D Box");
	visual3DBox->SetParent(visualTab);
	*/

	LCheckBox* visualHealthbars = new LCheckBox();
	visualHealthbars->SetPos(10, 60);
	visualHealthbars->SetVar(&CheatVariables::visual_healthbar);
	visualHealthbars->SetText("Draw Health");
	visualHealthbars->SetParent(visualTab);

	LCheckBox* visualWeaponEsp = new LCheckBox();
	visualWeaponEsp->SetPos(10, 85);
	visualWeaponEsp->SetVar(&CheatVariables::visual_weaponesp);
	visualWeaponEsp->SetText("Draw Weapon");
	visualWeaponEsp->SetParent(visualTab);

	LCheckBox* visualHitboxEsp = new LCheckBox();
	visualHitboxEsp->SetPos(10, 135);
	visualHitboxEsp->SetVar(&CheatVariables::visual_hitboxesp);
	visualHitboxEsp->SetText("Hitbox ESP");
	visualHitboxEsp->SetParent(visualTab);

	LCheckBox* visualBoneEsp = new LCheckBox();
	visualBoneEsp->SetPos(10, 160);
	visualBoneEsp->SetVar(&CheatVariables::visual_boneesp);
	visualBoneEsp->SetText("Bone ESP");
	visualBoneEsp->SetParent(visualTab);

	LCheckBox* visualChams = new LCheckBox();
	visualChams->SetPos(10, 185);
	visualChams->SetVar(&CheatVariables::visual_chams);
	visualChams->SetText("Player Chams");
	visualChams->SetParent(visualTab);

	/*
	LCheckBox* visualCrosshair = new LCheckBox();
	visualCrosshair->SetPos(10, 210);
	visualCrosshair->SetVar(&CheatVariables::visual_crosshair);
	visualCrosshair->SetText("Draw Crosshair");
	visualCrosshair->SetParent(visualTab);
	*/

	LBaseObject* miscTab   = tabProperty->AddTab("Misc");

	LCheckBox* miscNoRecoil = new LCheckBox();
	miscNoRecoil->SetPos(10, 10);
	miscNoRecoil->SetVar(&CheatVariables::misc_norecoil);
	miscNoRecoil->SetText("No Recoil");
	miscNoRecoil->SetParent(miscTab);

	LCheckBox* miscDisableNoVisualRecoil = new LCheckBox();
	miscDisableNoVisualRecoil->SetPos(300, 10);
	miscDisableNoVisualRecoil->SetVar(&CheatVariables::misc_disablevisualrecoil);
	miscDisableNoVisualRecoil->SetText("Disable No Recoil (Visual)");
	miscDisableNoVisualRecoil->SetParent(miscTab);

	LCheckBox* miscAdvertise = new LCheckBox();
	miscAdvertise->SetPos(300, 35);
	miscAdvertise->SetVar(&CheatVariables::misc_advertise);
	miscAdvertise->SetText("Advertise (Chat)");
	miscAdvertise->SetParent(miscTab);

	LCheckBox* miscNameSpam = new LCheckBox();
	miscNameSpam->SetPos(300, 60);
	miscNameSpam->SetVar(&CheatVariables::misc_namespam);
	miscNameSpam->SetText("Advertise (Name)");
	miscNameSpam->SetParent(miscTab);

	LCheckBox* miscNameSteal = new LCheckBox();
	miscNameSteal->SetPos(300, 85);
	miscNameSteal->SetVar(&CheatVariables::misc_namesteal);
	miscNameSteal->SetText("Namesteal");
	miscNameSteal->SetParent(miscTab);

	LCheckBox* miscNoRecoilAll = new LCheckBox();
	miscNoRecoilAll->SetPos(10, 35);
	miscNoRecoilAll->SetVar(&CheatVariables::misc_norecoilall);
	miscNoRecoilAll->SetText("No Recoil All");
	miscNoRecoilAll->SetParent(miscTab);

	LCheckBox* miscAntiFlash = new LCheckBox();
	miscAntiFlash->SetPos(10, 60);
	miscAntiFlash->SetVar(&CheatVariables::misc_antiflash);
	miscAntiFlash->SetText("Anti Flash");
	miscAntiFlash->SetParent(miscTab);

	LCheckBox* miscAutoDuck = new LCheckBox();
	miscAutoDuck->SetPos(10, 110);
	miscAutoDuck->SetVar(&CheatVariables::misc_autoduck);
	miscAutoDuck->SetText("Auto Duck");
	miscAutoDuck->SetParent(miscTab);

	LCheckBox* miscAutoStop = new LCheckBox();
	miscAutoStop->SetPos(10, 135);
	miscAutoStop->SetVar(&CheatVariables::misc_autostop);
	miscAutoStop->SetText("Auto Stop");
	miscAutoStop->SetParent(miscTab);

	LCheckBox* miscBhop = new LCheckBox();
	miscBhop->SetPos(10, 160);
	miscBhop->SetVar(&CheatVariables::misc_bhop);
	miscBhop->SetText("Auto Bhop");
	miscBhop->SetParent(miscTab);

	/*
	LCheckBox* miscAutohop = new LCheckBox();
	miscAutohop->SetPos(10, 10);
	miscAutohop->SetVar(&CheatVariables::misc_autohop);
	miscAutohop->SetText("Autohop");
	miscAutohop->SetParent(miscTab);

	LCheckBox* miscAutostrafe = new LCheckBox();
	miscAutostrafe->SetPos(10, 35);
	miscAutostrafe->SetVar(&CheatVariables::misc_autostrafe);
	miscAutostrafe->SetText("Autostrafe");
	miscAutostrafe->SetParent(miscTab);

	LCheckBox* miscNoRecoil = new LCheckBox();
	miscNoRecoil->SetPos(10, 60);
	miscNoRecoil->SetVar(&CheatVariables::misc_norecoil);
	miscNoRecoil->SetText("No Recoil");
	miscNoRecoil->SetParent(miscTab);

	LCheckBox* miscChatSpam = new LCheckBox();
	miscChatSpam->SetPos(10, 85);
	miscChatSpam->SetVar(&CheatVariables::misc_chatspam);
	miscChatSpam->SetText("Chat Spam");
	miscChatSpam->SetParent(miscTab);

	LCheckBox* miscNamesteal = new LCheckBox();
	miscNamesteal->SetPos(10, 110);
	miscNamesteal->SetVar(&CheatVariables::misc_namesteal);
	miscNamesteal->SetText("Name Stealer");
	miscNamesteal->SetParent(miscTab);
	*/

	LBaseObject* hvhTab = tabProperty->AddTab("HvH");

	LCheckBox* hvhInvert = new LCheckBox();
	hvhInvert->SetPos(10, 10);
	hvhInvert->SetVar(&CheatVariables::hvh_invert);
	hvhInvert->SetText("Invert AA");
	hvhInvert->SetParent(hvhTab);

	LCheckBox* hvhJitter = new LCheckBox();
	hvhJitter->SetPos(10, 35);
	hvhJitter->SetVar(&CheatVariables::hvh_jitter);
	hvhJitter->SetText("Jitter AA");
	hvhJitter->SetParent(hvhTab);

	//

	LBaseObject* colorTab  = tabProperty->AddTab("Color");
	
	LColorPicker* FGColor = new LColorPicker();
	FGColor->SetPos(10, 10);
	FGColor->SetVar(&LMenuFG);
	FGColor->SetColor(LMenuFG);
	FGColor->SetText("Foreground Color");
	FGColor->SetParent(colorTab);

	LColorPicker* BGColor = new LColorPicker();
	BGColor->SetPos(10, 130);
	BGColor->SetVar(&LMenuBG);
	BGColor->SetColor(LMenuBG);
	BGColor->SetText("Background Color");
	BGColor->SetParent(colorTab);

	tabProperty->SetCurrentTab(0);

}