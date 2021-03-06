// f00293_gamesound.h
//

#include "f00293_gamesound.e"
#define LZZ_INLINE inline
GameSound::GameSound ()
                            {
			curVolume = 0.0;
		}
void GameSound::init (string path)
                                       {
			if (!buffer.loadFromFile(path)) {
				cout << "error loading sound";
				return;
			}
			
			sound.setBuffer(buffer);
			
		}
void GameSound::setPitch (float val)
                                         {
			sound.setPitch(val);
		}
void GameSound::setPositionAndMinDis (float x, float y, float z, float w)
                  {
			sound.setMinDistance(w);
			sound.setPosition(x,y,z);
		}
void GameSound::setLoop (bool val)
                                       {
			sound.setLoop(val);
		}
void GameSound::stop ()
                            {
			
		}
void GameSound::setVolumeSmooth (float volume, float decay)
                {
			
			curVolume += (volume-curVolume)*decay;
			
			
			int intVol = curVolume*100.0f;
			sound.setVolume(intVol);
					
		}
void GameSound::setVolume (float volume)
                {
			curVolume = volume;
			int intVol = volume*100.0f;
			sound.setVolume(intVol);			
		}
void GameSound::play (float volume)
                {
			curVolume = volume;
			int intVol = volume*100.0f;
			
			sound.setVolume(intVol);
			sound.play();
			
		}
#undef LZZ_INLINE
 
