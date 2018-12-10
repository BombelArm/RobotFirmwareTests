/*
 * Counter.hpp
 *
 *  Created on: Nov 27, 2018
 *      Author: michal
 */

#ifndef BOMBLOS_COUNTER_HPP_
#define BOMBLOS_COUNTER_HPP_

#include "stdint.h"

template<typename ObjT >
class Counter{
	public:
		typedef void(ObjT::*CallbackT)();

		Counter(int period,CallbackT cb, ObjT* obj):
			cb_(cb),
			obj_(obj),
			period_(period),
			state_(0),
			overflowed_(0),
			started_(false){};

		void resetState(){
			state_= 0;
		};

		void clearOverflow(){
			overflowed_ = 0;
		}
		void inc(){
			if(!started_) return;
			state_++;
			if(state_ >= period_){
				overflowed_= 1;
				(obj_->*cb_)();
			}
		};

		uint32_t getState(){
			return state_;
		};

		void start(){
			started_ = true;
		}

		void stop(){
			started_ = false;
		}

	private:
		uint8_t started_;
		uint32_t state_;
		uint32_t period_;
		uint8_t overflowed_;
		CallbackT cb_;
		ObjT* obj_;
};


#endif /* BOMBLOS_COUNTER_HPP_ */
