local pMeta = FindMetaTable("Player")

if SERVER then

	util.AddNetworkString("add_clientmodel")
	util.AddNetworkString("add_clientmodels")

	util.AddNetworkString("cl_set_models")

	local function SendCModels(ply)

		net.Start("add_clientmodels")
			net.WriteEntity(ply)
			net.WriteTable(ply.CModels)
		net.Broadcast()

	end

	local function SendCModel(ply, index)

		local models = ply.CModels[index]

		net.Start("add_clientmodel")
			net.WriteEntity(ply)
			net.WriteInt(index, 32)
			net.WriteTable(models)
		net.Broadcast()

	end

	function pMeta:SendCModels(ply)

		net.Start("add_clientmodels")
			net.WriteEntity(ply)
			net.WriteTable(ply.CModels or {})
		net.Send(self)

	end

	function pMeta:SendCModel(ply, index)

		local models = ply.CModels[index]

		net.Start("add_clientmodel")
			net.WriteEntity(ply)
			net.WriteInt(index, 32)
			net.WriteTable(models)
		net.Send(self)

	end

	function pMeta:SetupCModels()

		self.CModels = {}
		SendCModels(self)

		/*
		models/weapons/w_rif_ak47.mdl
		models/weapons/w_rif_m4a1_silencer.mdl
		models/weapons/w_snip_awp.mdl
		models/weapons/w_smg_p90.mdl
		models/weapons/w_pist_deagle.mdl
		models/props/CS_militia/axe.mdl

		models/katharsmodels/handcuffs/handcuffs-1.mdl

		models/nater/weedplant_pot.mdl
		models/nater/weedplant_pot_dirt.mdl
		models/nater/weedplant_pot_planted.mdl
		models/nater/weedplant_pot_growing1.mdl
		models/nater/weedplant_pot_growing7.mdl
		*/

	end

	function pMeta:SyncCModels()

		for _, ply in pairs(player.GetAll()) do
			self:SendCModels(ply)
		end

	end

	net.Receive("cl_set_models", function( len, ply )

		local models = net.ReadTable()

		ply.CModels = models

		SendCModels(ply)

	end)

else

	local INVALID_PLYS = {}

	local function ClearCModels(tbl)

		for k, cmodel in pairs(tbl) do
			if IsValid(cmodel) then
				cmodel:Remove()
				tbl[k] = nil
			end
		end

	end

	net.Receive("add_clientmodels", function( len )

		local ply = net.ReadEntity()
		local cmodels = net.ReadTable()

		if !IsValid(ply) then
			INVALID_PLYS[ply] = cmodels
			return
		end

		ply.CModels = ply.CModels or {}

		ClearCModels(ply.CModels)

		for mdl_id, mdl_skin in pairs(cmodels) do
			ply.CModels[mdl_id] = ClientsideModel(CMODELS[mdl_id].model, RENDERGROUP_OPAQUE)
			//ply.CModels[mdl_id]:SetSkin(mdl_skin)
			ply.CModels[mdl_id].mdl_skin = mdl_skin
			ply.CModels[mdl_id]:SetNoDraw(true)
			ply.CModels[mdl_id].Draw = function()
						 
			end
		end

		if ply == LocalPlayer() then
			ply.PreviewCModels = ply.CModels
		end

	end)

	hook.Add("Think", "cmodel_think", function()

		for ply, cmodels in pairs(INVALID_PLYS) do
			if IsValid(ply) then

				ClearCModels(ply.CModels)

				for mdl_id, mdl_skin in pairs(cmodels) do
					ply.CModels[mdl_id] = ClientsideModel(CMODELS[mdl_id].model, RENDERGROUP_OPAQUE)
					ply.CModels[mdl_id].mdl_skin = mdl_skin
					ply.CModels[mdl_id]:SetNoDraw(true)

				end

				if ply == LocalPlayer() then
					ply.PreviewCModels = ply.CModels
				end

				INVALID_PLYS[ply] = nil
			end
		end

	end)

	/*
	net.Receive("add_clientmodel", function( len )

		local ply = net.ReadEntity()
		local index = net.ReadInt(32)
		local models = net.ReadTable()

		ply.CModels = ply.CModels or {}

		for ind, model in pairs(models) do
			ply.CModels[index] = ply.CModels[index] or {}
			ply.CModels[index][ind] = ClientsideModel(model, RENDERGROUP_TRANSLUCENT)
			ply.CModels[index][ind]:SetNoDraw(true)
		end

	end)
	*/

	local function DrawCModels( ent, models )

		if !IsValid( ent ) then return end

		for mdl_id, model in pairs(models or {}) do

			if !IsValid( model ) then continue end

			local mdl_info = table.Copy(CMODELS[mdl_id])
			local pmdl_info = table.Copy(PMODELS[LocalPlayer():GetModel()] or {})

			local pos, ang = Vector(), Angle()

			if mdl_info.att then
				local att = ent:GetAttachment( ent:LookupAttachment(mdl_info.att) )
				pos, ang = att.Pos, att.Ang
				if pmdl_info[mdl_info.att] != nil then
					pmdl_info = pmdl_info[mdl_info.att]
				end
			elseif mdl_info.bone then
				local bone = ent:LookupBone(mdl_info.bone)
				pos, ang = ent:GetBonePosition(bone)
				if pmdl_info[mdl_info.bone] != nil then
					pmdl_info = pmdl_info[mdl_info.bone]
				end
			else continue end

			local fwd = (ang:Forward() * ( (mdl_info.fwd or 0) + (pmdl_info.fwd or 0) ))
			local up = (ang:Up() * ( (mdl_info.up or 0) + (pmdl_info.up or 0) ))
			local right = (ang:Right() * ( (mdl_info.right or 0) + (pmdl_info.right or 0) ))

			pos = pos + fwd + up + right
			mdl_info.ang = mdl_info.ang or Angle()

			ang:RotateAroundAxis(ang:Forward(), mdl_info.ang.x)
			ang:RotateAroundAxis(ang:Up(), mdl_info.ang.y)
			ang:RotateAroundAxis(ang:Right(), mdl_info.ang.z)

			model:SetSkin(model.mdl_skin or 0)

			if(isnumber(mdl_info.scale)) then
				model:SetModelScale(mdl_info.scale)
			elseif(mdl_info.scale != nil) then
				local m = Matrix()
				m:Scale(Vector(mdl_info.scale.x, mdl_info.scale.y, mdl_info.scale.z))
				model:EnableMatrix("RenderMultiply", m)
			end

			model:SetPos(pos)
			model:SetAngles(ang)
			model:SetRenderOrigin(pos)
			model:SetRenderAngles(ang)
			//model:SetupBones()
			model:DrawModel()

		end

	end

	local eMeta = FindMetaTable("Entity")

	function eMeta:DrawCModels(models)
		DrawCModels( self, models )
	end

	hook.Add("PostDrawOpaqueRenderables", "DrawCModelsRagdolls", function()

		for k, ply in pairs(player.GetAll()) do
			
			if ply:Alive() then continue end

			local rag = ply:GetRagdollEntity()

			DrawCModels(rag, ply.CModels)

		end

	end)

	hook.Add("PostPlayerDraw", "DrawCModels", function( ply )

		if ply == LocalPlayer() then 
			ply.PreviewCModels = ply.PreviewCModels or ( ply.CModels or {})
			//if IsValid(MODEL_MENU) then
			DrawCModels(ply, ply.PreviewCModels)
			return
			//end 
		end

		DrawCModels(ply, ply.CModels)

	end)

end