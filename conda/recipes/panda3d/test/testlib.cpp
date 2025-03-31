#include "testlib.h"

#include <panda3d/configVariableBool.h>

#include <panda3d/windowFramework.h>
#include <panda3d/graphicsOutput.h>
#include <panda3d/graphicsEngine.h>
#include <panda3d/graphicsBuffer.h>
#include <panda3d/windowFramework.h>
#include <panda3d/graphicsOutput.h>
#include <panda3d/nodePath.h>
#include <panda3d/pointerTo.h>
#include <panda3d/camera.h>

int doStuff() {
  FrameBufferProperties fbp;
  fbp.set_rgb_color(true);
  fbp.set_float_depth(false);
  fbp.set_float_color(true);
  fbp.set_depth_bits(16);
  fbp.set_rgba_bits(32, 32, 32, 32);

  WindowProperties win_prop;
  win_prop.set_size(1024, 768);
  // Don't open a window - force it to be an offscreen buffer.
  int flags = GraphicsPipe::BF_refuse_window  | GraphicsPipe::BF_resizeable;
  GraphicsOutput *windowOutput;
  GraphicsEngine *engine;
  GraphicsPipe *pipe;

  DisplayRegion *region;
  region->set_clear_color(LColor(0.f));

  const auto dummy = ConfigVariableBool("dummy");
  return 0;
}
 