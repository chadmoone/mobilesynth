// lag_processor.h
// Author: Allen Porter <allen@thebends.org>
//
// A lag processor, used to implement glide.

#include "synth/parameter.h"
#include "synth/envelope.h"

#ifndef __LAG_PROCESSOR_H__
#define __LAG_PROCESSOR_H__

namespace synth {

class LagProcessor : public Parameter {
 public:
  LagProcessor(Parameter* param);
  virtual ~LagProcessor();

  // Number of samples for each 1.0 change in the parameters value
  void set_samples(long samples);
  void set_samples_up(long samples);
  void set_samples_down(long samples);

  virtual float GetValue();

 private:
  long samples_up_;
  long samples_down_;
  Parameter* param_;
  float last_value_;
  long samples_;

  Envelope envelope_;
};

}  // namespace

#endif  // __LOG_PROCESSOR_H__
