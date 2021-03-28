<h1 align="center">RemotePrinterController</h1>

<p align="center">
  <img alt="Github top language" src="https://img.shields.io/github/languages/top/S7Industries/RemotePrinterController?color=56BEB8">

  <img alt="Github language count" src="https://img.shields.io/github/languages/count/S7Industries/RemotePrinterController?color=56BEB8">

  <img alt="Repository size" src="https://img.shields.io/github/repo-size/S7Industries/RemotePrinterController?color=56BEB8">

  <img alt="License" src="https://img.shields.io/github/license/S7Industries/RemotePrinterController?color=56BEB8">

  <img alt="Github issues" src="https://img.shields.io/github/issues/S7Industries/RemotePrinterController?color=56BEB8" />
</p>

<p>
<img alt='M5StackImage' src="https://www.iloveimg.com/download/t8hwzg9tfvv4Alnsxzvkzl2zj2rxl9qh1zn66lvzv1lAhs1ggy72yg9y4svlc7fk9flhjxxfcy8fwb4pjvA33w2n8c2m6kdzw22qfcwql299svkthflbrs99jp4zgqk75lyw6569zdAc85v8n7b8fsclb2v7rrrfb7j05vmwmyv0p2lj4wl1/6">
</p>

<p align="center">
  <a href="#dart-about">About</a> &#xa0; | &#xa0; 
  <a href="#rocket-technologies">Technologies</a> &#xa0; | &#xa0;
  <a href="#checkered_flag-starting">Starting</a> &#xa0; | &#xa0;
  <a href="#memo-license">License</a> &#xa0; | &#xa0;
  <a href="https://github.com/MarcS7" target="_blank">Author</a>
</p>

<br>

## About ##

Using a <a href='https://m5stack-store.myshopify.com/collections/m5-core/products/m5stack-core2-esp32-iot-development-kit'>M5StackCore2</a> you will be able to see the status of your 3D printer. To develop this project we used the <a href='https://octoprint.org/'>Octoprint</a> APIs to request the data that comes from the printer. The M5Stack displays some data: at the moment we are asking for printer status, bed temperature and tool temperature. In the futher releases we will implement more control from the M5Stack to the printer like cancel a print or control the axes. We can do this because the M5Stack have integrated the ESP32 and a touch display which we will use to select printer options.
Octoprint is used as interface between the M5Stack and the printer: through its APIs we can interact with the printer and take the full control. The APIs are REST based so we use HTTP requests to take the data.

## Technologies ##

The following tools were used in this project:

- [PlatformIO](https://platformio.org/)
- [VSCode](https://code.visualstudio.com/)
- [ArduinoJson](https://arduinojson.org/)
- [M5Core2](https://github.com/m5stack/M5Core2)

## Starting ##

```bash
# Clone this project
$ git clone https://github.com/S7Industries/RemotePrinterController

# Access
$ cd remoteprintercontroller
```

Now you need to install PlatformIO into VSCode and than open the project.

You can even use Atom instead of VScode.
See PlatformIO site for supported IDEs.

## License ##

This project is under license from MIT. For more details, see the [LICENSE](LICENSE.md) file.


Made with :heart: by <a href="https://github.com/MarcS7" target="_blank">MarcS7</a>

&#xa0;

<a href="#top">Back to top</a>
