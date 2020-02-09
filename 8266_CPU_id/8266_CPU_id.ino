//Y.A.K.E
//获取8266硬件ID

#include <Esp.h>

  
///寄存

uint16_t _vcc  ; //不知道这是什么

uint32_t _cpu_id ;
uint8_t  _cpu_speed;

uint32_t _flash_id ;
FlashMode_t _flash_mode ;  //官方枚举类型

uint32_t _flash_real_size;
uint32_t _flash_speed;


const char *  _sdk_version ;
String        _core_version ;
String        _full_version ;


uint8_t _boot_version ;
uint8_t _boot_mode;




uint32_t _spiffs_size;
String _spiffs_md5 ;
uint32_t _spiffs_free_size;
 


//引用官方类
EspClass espclass; 


//计算大小.引自官方spiffs demo;
String formatBytes(uint32_t bytes) {
  if (bytes < 1024) {
    return String(bytes) + "B";
  } else if (bytes < (1024 * 1024)) {
    return String(bytes / 1024.0) + "KB";
  } else if (bytes < (1024 * 1024 * 1024)) {
    return String(bytes / 1024.0 / 1024.0) + "MB";
  } else {
    return String(bytes / 1024.0 / 1024.0 / 1024.0) + "GB";
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  delay(1500);

  _vcc = espclass.getVcc();
  
  _cpu_id = espclass.getChipId();
  _cpu_speed= espclass.getCpuFreqMHz();


  _flash_id = espclass.getFlashChipId(); 

  _flash_mode = espclass.getFlashChipMode();

_flash_real_size = espclass.getFlashChipRealSize();
_flash_speed =   espclass.getFlashChipSpeed() ;

_sdk_version = espclass.getSdkVersion();
_core_version = espclass.getCoreVersion();
_full_version = espclass.getFullVersion();

_boot_version= espclass.getBootVersion();

_boot_mode = espclass.getBootMode();

_spiffs_size = espclass.getSketchSize();
_spiffs_md5 = espclass.getSketchMD5();
_spiffs_free_size = espclass.getFreeSketchSpace();


  Serial.printf("vcc : %u \n\n",_vcc);
  
  Serial.printf("cpu id: %u \n",_cpu_id);
  Serial.printf("cpu speed: %u \n\n",_cpu_speed);
  
  Serial.printf("flash id: %u \n",_flash_id);
  
  
  

  String tmp_mode_str = "" ;
  switch(_flash_mode) {
    case FM_QIO: tmp_mode_str = "QIO";  break;
    case FM_QOUT: tmp_mode_str = "QOUT";  break;
    case FM_DIO: tmp_mode_str = "DIO"; break;
    case FM_DOUT: tmp_mode_str = "DOUT"; break;
    case FM_UNKNOWN: tmp_mode_str = "UNKNOWN"; break;
  }
  
  Serial.print("flash mode : ");
  Serial.println(tmp_mode_str);

  Serial.print("flash real size : ");
  Serial.println(formatBytes(_flash_real_size));

  Serial.print("flash speed : ");
  Serial.println(_flash_speed);  
  Serial.println(); 


  Serial.print("sdk version : ");
  Serial.println(_sdk_version);  
  Serial.print("core version : ");
  Serial.println(_core_version); 
  Serial.print("full version : ");
  Serial.println(_full_version); 
  Serial.println(); 
  
  Serial.print("boot version : ");
  Serial.println(_boot_version);     
  Serial.print("boot mode : ");
  Serial.println(_boot_mode); 
  Serial.println(); 


  Serial.print("spiffs size : ");
  Serial.println(formatBytes(_spiffs_size));  
  Serial.print("spiffs md5 : ");
  Serial.println(_spiffs_md5); 
  Serial.print("spiffs free size : ");
  Serial.println(formatBytes(_spiffs_free_size)); 
  Serial.println(); 

  
}

void loop() {
  // put your main code here, to run repeatedly:


}
