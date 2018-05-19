# InterFace:  OpenBCI

### Introduction
InterFace is a wearable gaming interface used to control 2D games using facial expressions. InterFace consists of a set of 4 OpenBCI Ganglion EMG electrodes connected on the forehead, lower lip and on the left and right cheek. By using these electrodes we are able to map facial expressions to 5 different commands: up, down, left, right and shoot.

### Setup

First, install the libraries:
``` bash
npm install
pip install -r requirements.txt
```

Download Emulator: http://www.completeroms.com/dl/gameboy-advance/super-mario-advance-4-super-mario-bros-3-u-/788

(If you don't have `npm`, you can install by running `brew install node`. You can get `brew` from https://brew.sh/)

### Stimulus Presentation + Recording


- Attach Ganglion to participant's face: 
  - Channel 1: Forehead
  - Channel 2: Left cheek
  - Channel 3: Right cheek
  - Channel 4: Chin
- Have participant sit in chair in front of monitor
- Connect to the ganglion and stream data: `node ganglion-lsl.js`
- Run lsl-viewer to check connections and stream: `python lsl-viewer.py`
- Check calibration values

``` python
decrease_fs = [4, 8]
increase_fs = [12, 20]
```

References:

[1] Arns, M., de Ridder, S., Strehl, U., Breteler, M., & Coenen, A. (2009). Efficacy of neurofeedback treatment in ADHD: the effects on inattention, impulsivity and hyperactivity: a meta-analysis. Clinical EEG and neuroscience, 40(3), 180-189. [(PDF)](http://www.bakerneuropsychology.com/files/Arns_2009_ClinEEGNeurosci_Efficacy_for_ADHD_meta-analysis.pdf)
