class VideoSharingPlatform {
    struct VideoRecord {
        string videoData;
        int viewsCount = 0;
        int likesCount = 0;
        int dislikesCount = 0;
    };

    set<int> recycledIds;
    int nextId;
    unordered_map<int, VideoRecord> videoDatabase;

public:
    VideoSharingPlatform() : nextId(0) {}

    int upload(string video) {
        int id;
        if (!recycledIds.empty()) {
            id = *recycledIds.begin();
            recycledIds.erase(recycledIds.begin());
        } else {
            id = nextId++;
        }
        VideoRecord rec;
        rec.videoData = video;
        videoDatabase[id] = rec;
        return id;
    }

    void remove(int videoId) {
        if (videoDatabase.count(videoId)) {
            videoDatabase.erase(videoId);
            recycledIds.insert(videoId);
        }
    }

    string watch(int videoId, int startMinute, int endMinute) {
        if (!videoDatabase.count(videoId)) return "-1";
        videoDatabase[videoId].viewsCount++;
        const string& data = videoDatabase[videoId].videoData;
        int len = static_cast<int>(data.size());
        if (startMinute >= len) return "";
        return data.substr(startMinute, min(endMinute, len - 1) - startMinute + 1);
    }

    void like(int videoId) {
        if (videoDatabase.count(videoId)) {
            videoDatabase[videoId].likesCount++;
        }
    }

    void dislike(int videoId) {
        if (videoDatabase.count(videoId)) {
            videoDatabase[videoId].dislikesCount++;
        }
    }

    vector<int> getLikesAndDislikes(int videoId) {
        if (!videoDatabase.count(videoId)) return {-1};
        return {videoDatabase[videoId].likesCount, videoDatabase[videoId].dislikesCount};
    }

    int getViews(int videoId) {
        if (!videoDatabase.count(videoId)) return -1;
        return videoDatabase[videoId].viewsCount;
    }
};
