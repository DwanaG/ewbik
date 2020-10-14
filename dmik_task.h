/*************************************************************************/
/*  dmik_task.h                                                          */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                      https://godotengine.org                          */
/*************************************************************************/
/* Copyright (c) 2007-2019 Juan Linietsky, Ariel Manzur.                 */
/* Copyright (c) 2014-2019 Godot Engine contributors (cf. AUTHORS.md)    */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/

#ifndef dmik_task_h__
#define dmik_task_h__

#include "bone_chain_item.h"
#include "qcp.h"

class DMIKTask : public Reference {
	GDCLASS(DMIKTask, Reference);

protected:
	static void _bind_methods() {}

public:
	Skeleton3D *skeleton = nullptr;
	Ref<QCP> qcp;
	Ref<DMIKShadowSkeletonBone> chain = memnew(DMIKShadowSkeletonBone);
	// Settings
	float min_distance = 0.01f;
	int iterations = 4;
	int max_iterations = 1.0f;
	// dampening dampening angle in radians.
	// Set this to -1 if you want to use the armature's default.
	float dampening = 0.05f;
	// stabilizing_passes number of stabilization passes to run.
	// Set this to -1 if you want to use the armature's default.
	int stabilizing_passes = -1;

	// Bone data
	int root_bone = -1;
	Vector<Ref<DMIKBoneEffectorTransform>> end_effectors;
	Ref<SkeletonModification3DDMIK> dmik;
};
#endif // dmik_task_h__
