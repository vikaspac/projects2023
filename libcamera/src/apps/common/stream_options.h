/* SPDX-License-Identifier: GPL-2.0-or-later */
/*
 * Copyright (C) 2020, Raspberry Pi Ltd
 *
 * stream_options.h - Helper to parse options for streams
 */

#pragma once

#include <optional>

#include <libcamera/camera.h>

#include "options.h"

class StreamKeyValueParser : public KeyValueParser
{
public:
	StreamKeyValueParser();

	KeyValueParser::Options parse(const char *arguments) override;

	static libcamera::StreamRoles roles(const OptionValue &values);
	static int updateConfiguration(libcamera::CameraConfiguration *config,
				       const OptionValue &values);

private:
	static std::optional<libcamera::StreamRole> parseRole(const KeyValueParser::Options &options);
};
