//
// Created by Raymond_Lx on 2020/6/6.
//

#include "SpinePathConstraint.h"

void SpinePathConstraint::_bind_methods(){
	ClassDB::bind_method(D_METHOD("apply"), &SpinePathConstraint::apply);
	ClassDB::bind_method(D_METHOD("update"), &SpinePathConstraint::update);
	ClassDB::bind_method(D_METHOD("get_order"), &SpinePathConstraint::get_order);
	ClassDB::bind_method(D_METHOD("get_position"), &SpinePathConstraint::get_position);
	ClassDB::bind_method(D_METHOD("set_position", "v"), &SpinePathConstraint::set_position);
	ClassDB::bind_method(D_METHOD("get_spacing"), &SpinePathConstraint::get_spacing);
	ClassDB::bind_method(D_METHOD("set_spacing", "v"), &SpinePathConstraint::set_spacing);
	ClassDB::bind_method(D_METHOD("get_rotate_mix"), &SpinePathConstraint::get_rotate_mix);
	ClassDB::bind_method(D_METHOD("set_rotate_mix", "v"), &SpinePathConstraint::set_rotate_mix);
	ClassDB::bind_method(D_METHOD("get_translate_mix"), &SpinePathConstraint::get_translate_mix);
	ClassDB::bind_method(D_METHOD("set_translate_mix", "v"), &SpinePathConstraint::set_translate_mix);
	ClassDB::bind_method(D_METHOD("get_bones"), &SpinePathConstraint::get_bones);
	ClassDB::bind_method(D_METHOD("get_target"), &SpinePathConstraint::get_target);
	ClassDB::bind_method(D_METHOD("set_target", "v"), &SpinePathConstraint::set_target);
	ClassDB::bind_method(D_METHOD("get_data"), &SpinePathConstraint::get_data);
	ClassDB::bind_method(D_METHOD("is_active"), &SpinePathConstraint::is_active);
	ClassDB::bind_method(D_METHOD("set_active", "v"), &SpinePathConstraint::set_active);
}

SpinePathConstraint::SpinePathConstraint():path_constraint(NULL) {}
SpinePathConstraint::~SpinePathConstraint() {}

void SpinePathConstraint::apply(){
	path_constraint->apply();
}

void SpinePathConstraint::update(){
	path_constraint->update();
}

int SpinePathConstraint::get_order(){
	return path_constraint->getOrder();
}

float SpinePathConstraint::get_position(){
	return path_constraint->getPosition();
}
void SpinePathConstraint::set_position(float v){
	path_constraint->setPosition(v);
}

float SpinePathConstraint::get_spacing(){
	return path_constraint->getSpacing();
}
void SpinePathConstraint::set_spacing(float v){
	path_constraint->setSpacing(v);
}

float SpinePathConstraint::get_rotate_mix(){
	return path_constraint->getRotateMix();
}
void SpinePathConstraint::set_rotate_mix(float v){
	path_constraint->setRotateMix(v);
}

float SpinePathConstraint::get_translate_mix(){
	return path_constraint->getTranslateMix();
}
void SpinePathConstraint::set_translate_mix(float v){
	path_constraint->setTranslateMix(v);
}

Array SpinePathConstraint::get_bones(){
	auto &bs = path_constraint->getBones();
	Array gd_bs;
	gd_bs.resize(bs.size());
	for(size_t i=0; i<bs.size(); ++i){
		auto b = bs[i];
		if(b == NULL) gd_bs[i] = Ref<SpineBone>(NULL);
		Ref<SpineBone> gd_b(memnew(SpineBone));
		gd_b->set_spine_object(b);
		gd_bs[i] = gd_b;
	}
	return gd_bs;
}

Ref<SpineSlot> SpinePathConstraint::get_target(){
	auto s = path_constraint->getTarget();
	if(s == NULL) return NULL;
	Ref<SpineSlot> gd_s(memnew(SpineSlot));
	gd_s->set_spine_object(s);
	return gd_s;
}
void SpinePathConstraint::set_target(Ref<SpineSlot> v){
	if(v.is_valid()){
		path_constraint->setTarget(v->get_spine_object());
	}else{
		path_constraint->setTarget(NULL);
	}
}

Ref<SpinePathConstraintData> SpinePathConstraint::get_data(){
	auto &sd = path_constraint->getData();
	Ref<SpinePathConstraintData> gd_sd(memnew(SpinePathConstraintData));
	gd_sd->set_spine_object(&sd);
	return gd_sd;
}

bool SpinePathConstraint::is_active(){
	return path_constraint->isActive();
}
void SpinePathConstraint::set_active(bool v){
	path_constraint->setActive(v);
}