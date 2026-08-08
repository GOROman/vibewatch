# Vibe Watch

[English](README.md) | [日本語](README.ja.md) | **简体中文**

[![Firmware build](https://github.com/GOROman/vibewatch/actions/workflows/firmware.yml/badge.svg)](https://github.com/GOROman/vibewatch/actions/workflows/firmware.yml)

**以M5Stack StopWatch为核心打造的可穿戴触觉控制界面，专为AI辅助Vibe Coding而设计。**

本项目参加[M5Stack Global Innovation Contest 2026](https://m5stack.com/global-innovation-contest-2026)。

![佩戴在手腕上的Vibe Watch及其Vibe Coding操作界面](docs/images/vibe-watch-hero.jpg)

## 一眼掌握，一触操作，保持专注

Vibe Watch将常用的AI智能体操作从拥挤的桌面界面转移到专用无线设备。它能让六个智能体的状态一目了然，将批准与拒绝变成实体操作，并把Plan模式、助手调用和按住说话功能放到手腕上。

目标很简单：把注意力从操作AI转回与AI共同创造。

## 创作动机

在Vibe Coding中，同时运行多个AI智能体会话已经成为常态。这也带来了新的交互问题：我希望在任务完成的瞬间就能发现它，选择正确的会话，并通过语音输入下一条提示，而不必在多个窗口之间寻找或回到键盘前。

购买[OpenAI Codex Micro](https://learn.chatgpt.com/docs/features/codex-micro)后，专用AI编程硬件的理念给了我灵感。我相信，将圆形屏幕、直接控制、动画、声音、触觉和语音输入结合起来，可以做出更小、更直观、更有表现力的体验。于是，面向并行会话的可穿戴AI驾驶舱Vibe Watch诞生了。

## 使用体验

启动时，Vibe Watch标识渐显，原创NES风格芯片音乐响起，进度条增长至实测电池电量。

主**智能体层**将六个实时智能体指示器排列在圆形屏幕周围。主机发送的颜色、亮度和动画用于表达状态；快速弹簧动画让选择环自然移动到下一个智能体。

同时按下两个实体按键，界面会变换为**操作层**：

| 控件 | 体验 |
|---|---|
| **FAST** | 触发快速操作 |
| **NG / OK** | 通过不同的方波音效和振动执行拒绝或批准 |
| **PLAN** | 切换Plan模式并显示当前状态 |
| **AI** | 调用AI助手 |
| **中央麦克风** | 按住进行语音输入 |

左侧橙色按键对应NG，右侧蓝色按键对应OK。彩色连线把实体按键与屏幕操作连接起来，无需说明也能理解它们的关系。

## 界面展示

<table>
  <tr>
    <td width="50%" valign="top"><img src="docs/images/vibe-watch-startup.jpg" alt="显示版本和电量的Vibe Watch启动画面"><br><strong>产品化启动体验</strong><br>渐显标识、原创启动音乐与实测电量动画。</td>
    <td width="50%" valign="top"><img src="docs/images/vibe-watch-agent-layer.jpg" alt="显示六个并行AI会话的智能体层"><br><strong>六个并行智能体</strong><br>无需遮挡编程界面，即可持续查看状态与选择。</td>
  </tr>
  <tr>
    <td width="50%" valign="top"><img src="docs/images/vibe-watch-action-layer.jpg" alt="显示FAST、NG、OK、PLAN、AI和语音输入的操作层"><br><strong>操作层</strong><br>从手腕即时使用FAST、NG、OK、PLAN、AI和语音输入。</td>
    <td width="50%" valign="top"><img src="docs/images/vibe-watch-settings.jpg" alt="蓝牙配对、音量和振动设置界面"><br><strong>设备内设置</strong><br>直接在手表上调整配对、音效音量、振动强度和状态变化振动。</td>
  </tr>
</table>

## 统一的多感官界面

Vibe Watch并不是在宏键盘上加一块装饰屏幕。视觉动画、声音提示、振动、触控和实体按键共同表达同一个交互状态。

- 上升的方波音效确认**OK**，下降的方波音效确认**NG**。
- 配对成功时同时提供声音和振动反馈。
- 智能体状态变化可以仅通过可调振动安静提示。
- 音效音量、振动强度和状态变化振动均可在设备上设置，并在重启后保留。

## M5Stack控制器的使用方式

M5Stack StopWatch是完整的产品界面，而不是连接到其他控制器的被动显示器。

- **ESP32-S3**负责界面、设置存储、电池监测和Bluetooth Low Energy HID通信。
- **466 × 466圆形触摸屏**显示六智能体空间界面和操作控件。
- 两个**实体按键**支持无需注视的导航、批准与拒绝。
- 内置**扬声器**和**振动电机**提供即时且易于区分的反馈。
- 集成**电池**让控制器可以无线携带。

紧密的软硬件整合把现成的M5Stack控制器变成了专用的人机AI交互界面。

## 从StopWatch到腕表

Vibe Watch将官方[Watch Accessory Kit for M5Stick Series](https://shop.m5stack.com/products/watch-accessory-kit-for-m5stick-series)改造为腕带支架。该套件为矩形M5Stick设备设计，因此需要对塑料Watch Mount Accessory进行少量加工，才能安装圆形StopWatch。

1. 切割前，从设备和表带上取下塑料支架。
2. 用斜口钳或小型剪钳逐步剪除固定M5Stick的凸起卡扣。
3. 修整毛刺和尖锐边缘，使粘接面保持平整。
4. 清洁支架与StopWatch背面，并使其完全干燥。
5. 将高强度双面胶裁剪到支架轮廓以内，不要遮挡按键、接口或开孔。
6. 将支架对准StopWatch背面中央，用力压紧，并按照胶带要求等待粘接完成。
7. 重新安装尼龙表带，佩戴前进行牢固的拉力测试。

这一改造无需切削StopWatch外壳，只使用改造后的套件零件和双面胶。无论坐在桌前还是移动中，界面都能随时使用。

## 影响与实用价值

Vibe Watch减少了AI辅助工作中频繁出现的细小中断。它持续显示多个智能体的活动，把批准变成确定的实体动作，并让用户即使离开键盘也能立即开始语音输入。

同样的交互模式还可以扩展到无障碍工具、创意应用、多智能体运维，以及任何注意力比屏幕空间更宝贵的工作流程。

## 使用的硬件

| 项目 | 数量 | 用途 |
|---|---:|---|
| [M5Stack StopWatch](https://docs.m5stack.com/en/core/StopWatch) | 1 | 控制器、显示、输入、声音、振动、BLE和供电 |
| [M5Stack Watch Accessory Kit for M5Stick Series](https://shop.m5stack.com/products/watch-accessory-kit-for-m5stick-series) | 1 | 尼龙表带和需要改造的Watch Mount Accessory |
| 高强度双面胶 | 1片 | 将改造后的支架固定到StopWatch |
| 支持蓝牙的macOS电脑 | 1 | AI编程主机 |

腕表改造工具：斜口钳或小型剪钳、可选的细锉刀以及护目镜。

## 构建与配对

安装[PlatformIO Core](https://docs.platformio.org/en/latest/core/installation/index.html)，然后克隆公开仓库并构建固件：

```sh
git clone https://github.com/GOROman/vibewatch.git
cd vibewatch
python3 -m platformio run -e m5stack-stopwatch
```

连接StopWatch并上传：

```sh
python3 -m platformio run -e m5stack-stopwatch --target upload
```

在Vibe Watch上打开Settings，选择三个设备槽位之一，点击**PAIR**，然后从macOS蓝牙设置连接到`Vibe Watch #n`。

## 许可证

[MIT License](LICENSE)

## 参考资料

- [M5Stack StopWatch — 官方文档](https://docs.m5stack.com/en/core/StopWatch)
- [M5Stack Watch Accessory Kit for M5Stick Series — 官方产品页面](https://shop.m5stack.com/products/watch-accessory-kit-for-m5stick-series)
- [OpenAI Codex Micro — 官方文档](https://learn.chatgpt.com/docs/features/codex-micro)
