//
// Created by stone on 2024-06-14.
//

#ifndef RESOURCEHOLDER_H
#define RESOURCEHOLDER_H

#include <memory>
#include <cassert>
#include <SFML/Graphics.hpp>

template <typename Resource, typename Identifier>
class ResourceHolder
{
public:
    void load(Identifier id,
              const std::string& filename);
    template <typename Parameter>
    void load(Identifier id, const std::string& filename, const Parameter& parameter);
    Resource& get(Identifier id);
    const Resource& get(Identifier id) const;
private:
    void insertResource(Identifier id, std::unique_ptr<Resource> resource);
private:
    std::map<Identifier, std::unique_ptr<Resource>> mResourceMap;
};

template<typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::load(Identifier id, const std::string &filename) {
    std::unique_ptr<Resource> resource(new Resource());
    if (!resource->loadFromFile(filename)) {
        throw std::runtime_error("TextureHolder::load - Failed to load " + filename);
    }
    auto inserted = mResourceMap.insert(
        std::make_pair(id, std::move(resource))
    );
    assert(inserted.second);
}
template <typename Resource, typename Identifier>
template <typename Parameter>
void ResourceHolder<Resource, Identifier>::load(Identifier id, const std::string& filename, const Parameter& secondParam)
{
    // Create and load resource
    std::unique_ptr<Resource> resource(new Resource());
    if (!resource->loadFromFile(filename, secondParam))
        throw std::runtime_error("ResourceHolder::load - Failed to load " + filename);

    // If loading successful, insert resource to map
    insertResource(id, std::move(resource));
}

template<typename Resource, typename Identifier>
Resource &ResourceHolder<Resource, Identifier>::get(Identifier id) {
    auto found = mResourceMap.find(id);
    assert(found != mResourceMap.end());
    return *found->second;
}

template<typename Resource, typename Identifier>
const Resource &ResourceHolder<Resource, Identifier>::get(Identifier id) const {
    auto found = mResourceMap.find(id);
    assert(found != mResourceMap.end());
    return *found->second;
}

template<typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::insertResource(Identifier id, std::unique_ptr<Resource> resource) {
    auto inserted = mResourceMap.insert(std::make_pair(id, std::move(resource)));
    assert(inserted.second);
}



#endif //RESOURCEHOLDER_H
