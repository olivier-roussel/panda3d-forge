// Include all the stuff
#include <panda3d/pandaFramework.h>
#include <panda3d/pandaSystem.h>
#include <panda3d/configFlags.h> // add this header to force compile with configFlags

int main(int argc, char *argv[]) {
  // // Open the framework
  // PandaFramework framework;
  // framework.open_framework(argc, argv);
  // // Set a nice title
  // framework.set_window_title("Hello World!");
  // // Open it!
  // WindowFramework *window = framework.open_window();

  // // Check whether the window is loaded correctly
  // if (window != nullptr) {
  //   nout << "Opened the window successfully!\n";

  //   window->enable_keyboard(); // Enable keyboard detection
  //   window->setup_trackball(); // Enable default camera movement

  //   // Put here your own code, such as the loading of your models

  //   // Do the main loop
  //   framework.main_loop();
  // } else {
  //   nout << "Could not load the window!\n";
  // }
  // // Close the framework
  // framework.close_framework();


  // FrameBufferProperties fbp;
  // fbp.set_rgb_color(true);
  // fbp.set_float_depth(false);
  // fbp.set_float_color(true);
  // fbp.set_depth_bits(16);
  // fbp.set_rgba_bits(32, 32, 32, 32);

  // WindowProperties win_prop;
  // win_prop.set_size(m_renderParameters.getImageWidth(), m_renderParameters.getImageHeight());
  // Don't open a window - force it to be an offscreen buffer.
  // int flags = GraphicsPipe::BF_refuse_window  | GraphicsPipe::BF_resizeable;
  GraphicsOutput *windowOutput;
  // GraphicsOutput *windowOutput = m_window->get_graphics_output();
  // GraphicsEngine *engine = windowOutput->get_engine();
  // GraphicsPipe *pipe = windowOutput->get_pipe();

  // static int id = 0;
  // m_normalDepthBuffer = engine->make_output(pipe, renderTypeToName(m_renderType) + std::to_string(id), m_renderOrder, fbp, win_prop, flags,
  //                                           windowOutput->get_gsg(), windowOutput);
  // m_normalDepthTexture = new Texture("geometry texture " + std::to_string(id));
  // ++id;
  // if (m_normalDepthBuffer == nullptr) {
  //   throw vpException(vpException::fatalError, "Could not create geometry info buffer");
  // }

  // m_buffers.push_back(m_normalDepthBuffer);
  PointerTo<GraphicsOutput> m_normalDepthBuffer;

  // m_normalDepthBuffer = engine->make_output(pipe, renderTypeToName(m_renderType) + std::to_string(id), m_renderOrder, fbp, win_prop, flags,
  //                                         windowOutput->get_gsg(), windowOutput);

  m_normalDepthBuffer->set_inverted(windowOutput->get_gsg()->get_copy_texture_inverted());
  return 0;
}
