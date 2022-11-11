#! /bin/sh

if [ -z "${TARGET}" ] ; then
    CURRENT_TARGET=gcw0
else
    CURRENT_TARGET=${TARGET}
fi

OPK_NAME=nblood-${CURRENT_TARGET}.opk

DESKTOP_FILE=default.${CURRENT_TARGET}.desktop
DESKTOP_CRYPTIC_FILE=cryptic.${CURRENT_TARGET}.desktop

echo ${OPK_NAME}

# create default.gcw0.desktop
cat > ${DESKTOP_FILE} <<EOF
[Desktop Entry]
Name=NBlood
Comment=Blood port
Exec=nblood
Terminal=false
Type=Application
StartupNotify=true
Icon=nblood
Categories=games;
X-OD-Manual=readme.nblood.txt
EOF

cat > ${DESKTOP_CRYPTIC_FILE} <<EOF
[Desktop Entry]
Name=Cryptic Passage 
Comment=Blood Cryptic Passage port
Exec=nblood -ini CRYPTIC.INI
Terminal=false
Type=Application
StartupNotify=true
Icon=nblood
Categories=games;
X-OD-Manual=readme.nblood.txt
EOF

# create opk
FLIST="${DESKTOP_FILE}"
FLIST="${FLIST} ${DESKTOP_CRYPTIC_FILE}"
FLIST="${FLIST} ./od-assets/nblood.png"
FLIST="${FLIST} ./od-assets/readme.nblood.txt"
FLIST="${FLIST} nblood"
FLIST="${FLIST} nblood.pk3"

rm -f ${OPK_NAME}
mksquashfs ${FLIST} ${OPK_NAME} -all-root -no-xattrs -noappend -no-exports

cat ${DESKTOP_FILE} ${DESKTOP_CRYPTIC_FILE}
rm -f ${DESKTOP_FILE} ${DESKTOP_CRYPTIC_FILE}
