#pragma once


//ofxWMFVideoPlayer addon written by Philippe Laulheret for Second Story (secondstory.com)
//Based upon Windows SDK samples
//MIT Licensing


#include "ofMain.h"
#include "ofxWMFVideoPlayerUtils.h"

#include "EVRPresenter.h"



class ofxWMFVideoPlayer;

class CPlayer;
class ofxWMFVideoPlayer : public ofBaseVideoPlayer {

private:
	CPlayer*	_player;

	int _id;

	static int  _instanceCount;

	HWND		_hwndPlayer;

	BOOL bRepaintClient;

	int _width;
	int _height;

	bool _waitingForLoad;
	bool _waitForLoadedToPlay;
	bool _isLoaded;
	bool _isLooping;
	bool _wantToSetVolume;
	float _currentVolume;

	bool _sharedTextureCreated;

	ofTexture _tex;
	ofTexture * playerTex;
	ofPixels _pixels;

	BOOL InitInstance();
	bool endLoad();

	void                OnPlayerEvent(HWND hwnd, WPARAM pUnkPtr);

	float _frameRate;

	void				setLoop(bool isLooping) { _isLooping = isLooping; _player->setLooping(isLooping); }

public:

	ofxWMFVideoPlayer();
	~ofxWMFVideoPlayer();

	bool				loadMovie(string name) { return loadMovie(name, false); }
	bool				loadMovie(string name, bool asynchronous);
	void				closeMovie() { close(); }
	void				close();

	void				update();
	void				play();
	void				stop();

	void				setPaused(bool bPause);

	float				getPosition();
	float				getPositionInSeconds();
	float				getDuration();
	float				getFrameRate();

	bool				canRewind() { return _player->canRewind(); }

	void				setPosition(float pct);

	void				setVolume(float vol);
	float				getVolume();

	float				getHeight() { return _player->getHeight(); }
	float				getWidth() { return _player->getWidth(); }

	bool				isLooping() { return _isLooping; }

	void				setLoopState(ofLoopType loopType);
	ofLoopType			getLoopState() { return _isLooping ? OF_LOOP_NORMAL : OF_LOOP_NONE; }
	bool				getIsMovieDone();

	bool				setSpeed(float speed, bool useThinning = false); //thinning drops delta frames for faster playback though appears to be choppy, default is false
	float				getSpeed();

	bool				isLoaded();

	unsigned char *		getPixels();
	ofPixelFormat		getPixelFormat();
	bool				isFrameNew();

	PlayerState getState() { return _player->GetState(); }
	bool isPlaying() { return _player->GetState() == Started; }
	bool isStopped() { return (_player->GetState() == Stopped || _player->GetState() == Paused); }
	bool isPaused() { return _player->GetState() == Paused; }

	ofPixels& getPixelsRef() { return _pixels; }
	ofTexture & getTextureReference() {
		if (playerTex == NULL) {
			return _tex;
		}
		else {
			return *playerTex;
		}
	};
	bool setPixelFormat(ofPixelFormat pixelFormat);

	void draw(int x, int y, int w, int h);
	void draw(int x, int y) { draw(x, y, getWidth(), getHeight()); }

	void setAnchorPercent(float xPct, float yPct) {
		if (_isLoaded) {
			_player->m_pEVRPresenter->lockSharedTexture();
				_tex.setAnchorPercent(xPct, yPct);
			_player->m_pEVRPresenter->unlockSharedTexture();
		}
	}
	void setAnchorPoint(float x, float y) {
		if (_isLoaded) {
			_player->m_pEVRPresenter->lockSharedTexture();
			_tex.setAnchorPoint(x, y);
			_player->m_pEVRPresenter->unlockSharedTexture();
		}
	}
	void resetAnchor() {
		if (_isLoaded) {
			_player->m_pEVRPresenter->lockSharedTexture();
			_tex.resetAnchor();
			_player->m_pEVRPresenter->unlockSharedTexture();
		}
	}

	HWND getHandle() { return _hwndPlayer; }
	LRESULT WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

	static void forceExit();

};