#!/bin/bash

set -e

KEY_NAME="id_ed25519_shenhavov"
KEY_PATH="$HOME/.ssh/$KEY_NAME"
GITHUB_HOST_ALIAS="github-shenhav"
GITHUB_USERNAME="shenhavov"
REPO_NAME="sandbox"

# 1. Generate SSH key if not exists
if [ ! -f "$KEY_PATH" ]; then
    echo "🔑 Generating new SSH key for $GITHUB_USERNAME..."
    ssh-keygen -t ed25519 -C "$GITHUB_USERNAME@github.com" -f "$KEY_PATH" -N ""
else
    echo "✅ SSH key already exists: $KEY_PATH"
fi

# 2. Add key to SSH agent
eval "$(ssh-agent -s)"
ssh-add "$KEY_PATH"

# 3. Create SSH config entry for alias
SSH_CONFIG="$HOME/.ssh/config"
if ! grep -q "$GITHUB_HOST_ALIAS" "$SSH_CONFIG" 2>/dev/null; then
    echo "🔧 Adding SSH config for $GITHUB_HOST_ALIAS..."
    cat <<EOF >> "$SSH_CONFIG"

# GitHub alias for shenhavov identity
Host $GITHUB_HOST_ALIAS
    HostName github.com
    User git
    IdentityFile $KEY_PATH
EOF
else
    echo "✅ SSH config already contains $GITHUB_HOST_ALIAS"
fi

# 4. Set origin remote to use the alias (in current repo)
echo "🔗 Setting Git remote to use alias..."
cd "$(git rev-parse --show-toplevel)" || exit 1
git remote set-url origin "git@$GITHUB_HOST_ALIAS:$GITHUB_USERNAME/$REPO_NAME.git"

# 5. Show confirmation
echo "✅ All set! You can now push using:"
echo "   git push"
